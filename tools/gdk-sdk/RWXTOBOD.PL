#!/usr/local/bin/perl
# Copyright (c) 1995-1999 Worlds Inc.  All Rights Reserved.
# By: steveco@west.net 09/28/98 -- 153: Make tail a replacable limb.
#     steveco 04/20/99 -- 1: Compress further; lossy.

my $filesInPairs = 0;
my $swapZY = 0;
my $unexplode = 0;

if (@ARGV >= 1 && $ARGV[0] eq "-pairs") {
    shift @ARGV;
    $filesInPairs = 1;
}

if (grep(/-unexplode/, @ARGV) > 0)
{
    print "Halving all transforms.\n";
    $unexplode = 1;
}

if (grep(/-swapYZ/, @ARGV) > 0)
{
    $swapZY = 1;
    print "Swapping Y and Z axes.\n";
}

if (@ARGV < 1 || $filesInPairs && (@ARGV % 2) != 0) {
    print "USAGE: $0 file1.rwx ...   or  $0 -pairs file1.rwx file1.bod ...\n";
    print "  example: $0 aura.rwx  <-- makes aura.bod from aura.rwx\n";
    exit;
}
		    
sub min {
    my $min = shift(@_);
    foreach $foo (@_) {
	$min = $foo if $foo < $min;
    }
    return $min;
}

sub max {
    my $max = shift(@_);
    foreach $foo (@_) {
	$max = $foo if $foo > $max;
    }
    return $max;
}

#
# Write out a .bod file in place of this .rwx.  .bod is a proprietary worlds
# format for custom avatars.  It represents those limbs of the av that have
# names on the %labels list as separate "parts".  Parts may in turn contain 
# other subclumps, for clumps that weren't on that list.
#
# The .rwx is the output from
# the rw3dconv converter, or from 3DSMax's export to rwx.  If the latter,
# the file will start with a comment with the word "plug-in", and is assumed
# to use a scaling value of 10 units per meter.  Otherwise the scaling is
# assumed to be 1 unit per centimeter, and translation values are assumed
# to be doubled due to a conversion bug in rw3dconv.
#
# Existing Ambient, Diffuse, and Specular values are ignored, and the 
# intensity of the given Color value used to compute lighting levels.  If a
# Surface value is provided, it is factored into the color value.
#
# Each limb object (clump) must be named from the %labels list; those with
# other names are not broken out into separate limbs.
#
#
# A bod file has the following format: (see also shape\nShape.cpp):
#
# Bytes
#  1    Version # (1 for this version)
#  1    # parts following
#       For each part:
#    1    Tag value
#    2    offset to clump start from 0 at end of this table.  Little endian.
# -->   For each clump:
#    1    Tag byte, high bit 1 means low7+(1<<27), indicates placeholder clump
#               and means that everything after translation values left out.
#    1    Flag byte, 
#           Bit 7 means the following vertex table includes UV values.
#           Bits 6, 5, and 4 indicate the presence of floats as follows:
#    3    X translation value, only if bit 1 set above.  Little endian.
#    3    Y translation value, only if bit 2 set above.  Little endian.
#    3    Z translation value, only if bit 3 set above.  Little endian.
#           3-byte floats should be recreated with the 4th byte set to 0.
#
#         Everything following exists only for non-placeholder clumps.
#    1    R of color
#    1    G of color
#    1    B of color
#    1    # vertices following
#    3,3     for v min,max(present only if flag bit 7 set, above)
#    3,3     for y min,max
#    3,3     for z min,max
#    3,3     for x min,max
#    3,3     for u min,max (present only if flag bit 7 set, above)
#           Vertices are given in the order vyzxu, which gives zip the most
#           opportunity for copying oft-repeated vy and vyz sequences.
#           Each value is a byte, from 0-255 a value linearly between min/max.
#      1    for v (present only if flag bit 7 set, above)
#      1    for y
#      1    for z
#      1    for x
#      1    for u (present only if flag bit 7 set, above)
#    1    # triangles following.
#         For each triangle after first (first is assumed to be 0 1 2):
#           Stored as a bit sequence little endian, with much of the
#           computation depending on the highest vertex value previously
#           encountered, hereafter called prevhigh.  Prevhigh=2 to start.
#           k = ceil(log2(prevhigh+3)) ie the number of bits needed to
#           represent numbers as large as prevhigh+3.
#      1 bit   v1 is prevhigh plus this value.
#      k bits  v2 is prevhigh minus this value.  
#            If v1=prevhigh+1=v2, skip v3, this is an escape code to advance
#            prevhigh without generating a triangle.
#      k bits  v3 is prevhigh minus this value (see above for when present).
#    1    # child clumps following.
#         For each clump: recurse to arrow at "For each clump" above.
#
# The generated file has "placeholder" clumps inserted (indicated by the
# high bit of the tag value byte), which are stub child
# clumps that have a transform and to which other "parts" attach.
# Any transform value in a part is moved into a placeholder in the parent
# when it is broken up by this program.
#
# Subclumps that aren't "parts" are kept as part of their containing clump.
#
%labels = (
    "pelvis" => "groi",
    "back" => "back",
    "neck" => "neck",
    "head" => "head",
    "rtshoulder" => "rupa",
    "rtelbow" => "rfor",
    "rtwrist" => "rhan",
    "lfshoulder" => "lupa",
    "lfelbow" => "lfor",
    "lfwrist" => "lhan",
    "rthip" => "rthi",
    "rtknee" => "rcal",
    "rtankle" => "rfoo",
    "lfhip" => "lthi",
    "lfknee" => "lcal",
    "lfankle" => "lfoo",
    "tail" => "tail"
);

%tags = (
    "pelvis" => 1,
    "back" => 2,
    "neck" => 3,
    "head" => 4,
    "rtsternum" => 5,
    "rtshoulder" => 6,
    "rtelbow" => 7,
    "rtwrist" => 8,
    "rtfingers" => 9,
    "lfsternum" => 10,
    "lfshoulder" => 11,
    "lfelbow" => 12,
    "lfwrist" => 13,
    "lffingers" => 14,
    "rthip" => 15,
    "rtknee" => 16,
    "rtankle" => 17,
    "rttoes" => 18,
    "lfhip" => 19,
    "lfknee" => 20,
    "lfankle" => 21,
    "lftoes" => 22,
    "back2" => 23,
    "tail" => 24,
    "mouth" => 25,
    "nose" => 26,
    "lfear" => 27,
    "rtear" => 28,
    "back3" => 29,
    "tail2" => 30,
    "tail3" => 31,
    "tail4" => 32
);

# Encode a float with 3 bytes, by throwing out the least significant
# mantissa byte.
sub packFloat {
    return substr(pack("f", $_[0]), 1, 3);
}

# Encode a float value as 1, as used for vertex values.
# The second param is a history array of all values encoded previously,
# and is used for the diff-relative coding method.  The final value is added
# to the end of the history array.
sub encodeVal {
    my ($val, $min, $max) = @_;
    
    if ($val < $min || $val > $max) {
	print "ERROR: $val is outside range $min,$max.\n";
	exit 1;
    }

    return pack("C", 0) if ($max == $min);

    # Encode the value in the range $min, $max, in one of 256 values.
    return int(255*($val - $min)/($max - $min) + 0.5);
}
		    
sub makeOrFindGroup {
    my ($groups, $color, $texture) = @_;
    
    if ($color eq "") {
	print "Note: no color available at first clump, using black.\n";
    }

    # Start a new group.  Use an existing one if the color and texture 
    # matches, and it's not already full.
    my $g;
    foreach $g (@{$groups}) {
	if (!$g->{full} && $g->{texture} eq $texture) {
	    my $gcol = $g->{color};
	    if ($gcol->[0] == $color->[0]
	     && $gcol->[1] == $color->[1] 
	     && $gcol->[2] == $color->[2]) 
	    {
		return $g;
	    }
	}
    }
	    
    $g = { color => $color,
	   full => 0,
	   texture => $texture,
	   tris => [],
	   verts => [],
	   origToNewVert => []
	 };
    
    push @{$groups}, $g;
    return $g;
}

sub pushTri {
    my ($cur, $groups, $tri, $numAllVerts) = @_;

    # If might overflow, switch to a new group.
    if (scalar @{$cur->{tris}} > 820 || scalar @{$cur->{verts}} > 252) {
	print "Note: switching to new group.\n";
	$cur->{full} = 1;
	$cur = makeOrFindGroup($groups, $cur->{color}, $cur->{texture});
    }

    push @{$cur->{tris}}, $tri;
    my $val;
    foreach $val (@$tri) {
	if ($cur->{origToNewVert}->[$val] eq "") {
	    if ($val >= $numAllVerts) {
		print "ERROR: Vertex $val not specified\n";
		exit -1;
	    }
	    
	    $cur->{origToNewVert}->[$val] = @{$cur->{verts}};
	    push @{$cur->{verts}}, $val;
	}
    }

    return $cur;
}

#$nextPartialBit; # From 1 to 128, the next bit value to add to $partialByte.
#$partialByte;

# Push param1, which is has a max value of param2-1, into the bit string,
# returning any finished bytes.
sub pushBits {
    my ($val, $cap) = @_;
    $val += $cap if ($val < 0);
    if ($val >= $cap || $val < 0) {
	print "BUG: pushing value $val with maximum $cap!\n";
	exit -1;
    }
    my $bit;
    my $result = "";
    for ($bit = 1; $bit < $cap; $bit <<= 1) {
	$partialByte += $nextPartialBit if $val & 1;
	$val >>= 1;
	if (($nextPartialBit <<= 1) == 256) {
	    $nextPartialBit = 1;
	    $result .= pack("C", $partialByte);
	    $partialByte = 0;
	}
    }
    return $result;
}

# Compress the given set of triangles in group.
sub compTris {
    my ($group, $tris) = @_;

    my $triData = "";
    $nextPartialBit = 1;
    $partialByte = 0;

    my $highest = 2;
    foreach $j (@$tris) {
	my $v1 = $group->{origToNewVert}->[$j->[0]];
	my $v2 = $group->{origToNewVert}->[$j->[1]];
	my $v3 = $group->{origToNewVert}->[$j->[2]];
#print "tri = $v1,$v2,$v3.\n";

	# Move min(highest of the three, $highest+1) to v1, preserving wiseness.
	my $biggest = max($v1, $v2, $v3);
	if ($biggest < $highest) {
	    print "BUG: sorted $v1,$v2,$v3 after a tri with $highest highest.\n";
	    exit -1;
	}

	my $cap = $highest+4;

	while ($biggest > $highest+1
	 && $v1 != $highest+1 && $v2 != $highest+1 && $v3 != $highest+1) 
	{
	    #print "WARNING: tri $v1,$v2,$v3 skips vert " . ($highest+1) . ".\n";
	    $triData .= pushBits(1, 2);    # Send "skip vert" code.
	    $triData .= pushBits(-1, $cap);
	    $highest++;
	    $cap++;
	}

	my $h = min($biggest, $highest+1); # Results in $highest or $highest+1.
	if ($h < $highest) {
	    print "BUG: biggest $biggest is somehow < highest $highest.\n";
	    exit -1;
	}

	# Rotate verts to get value $h into the first position.
	if ($v1 != $h) {
	    if ($v2 == $h) {
		$v2 = $v3;
		$v3 = $v1;
		$v1 = $h;
	    } elsif ($v3 == $h) {
		$v3 = $v2;
		$v2 = $v1;
		$v1 = $h;
	    } else {
		print "ERROR: Tri $v1,$v2,$v3 skips vertex $h.\n";
		exit -1;
	    }
	}

	$triData .= pushBits($h-$highest, 2);
	$triData .= pushBits($highest-$v2, $cap);
	$triData .= pushBits($highest-$v3, $cap);

	$highest = $biggest;
    }

    $triData .= pushBits(0, 128);  # Feed in 7 bits to flush out any leftovers.

#print "Encoded " . (@$tris+1) . " with " . length($triData) . "bytes.\n";

    $triBytes += length($triData);

    return $triData;
}

sub compareTris {
    my ($a1, $a2, $a3, $b1, $b2, $b3) = @_;
    my @as = ($a1, $a2, $a3);
    if ($as[0] > $as[1]) {
	my $t = $as[0];
	$as[0] = $as[1];
	$as[1] = $t;
    }
    if ($as[1] > $as[2]) {
	my $t = $as[1];
	$as[1] = $as[2];
	$as[2] = $t;
    }
    if ($as[0] > $as[1]) {
	my $t = $as[0];
	$as[0] = $as[1];
	$as[1] = $t;
    }
    my @bs = ($b1, $b2, $b3);
    if ($bs[0] > $bs[1]) {
	my $t = $bs[0];
	$bs[0] = $bs[1];
	$bs[1] = $t;
    }
    if ($bs[1] > $bs[2]) {
	my $t = $bs[1];
	$bs[1] = $bs[2];
	$bs[2] = $t;
    }
    if ($bs[0] > $bs[1]) {
	my $t = $bs[0];
	$bs[0] = $bs[1];
	$bs[1] = $t;
    }
    my $result = (((((($as[2] <=> $bs[2])
	or ($bs[1] <=> $as[1]))
	or ($bs[0] <=> $as[0]))
	or ($a1 <=> $b1))
	or ($a2 <=> $b2))
	or ($a3 <=> $b3));

    return $result;
} 

sub writeColorVertsAndTris {
    my ($data, $group, $uvflagPos, $allVertsPtr) = @_;
    
    my @color = @{$group->{color}};
    $$data .= pack("CCC", int($color[0]), int($color[1]), int($color[2]));
    
    my $hasUV = 0;
    my $j;
    if (@{$group->{verts}} >= 2) {
	$j = $group->{verts}->[0];
	my $uFirst = $allVertsPtr->[$j]->[3];
	my $vFirst = $allVertsPtr->[$j]->[4];
	
	# UV if any of the verts have a different UV value from the first.
	foreach $j (@{$group->{verts}}) {
	    if ($allVertsPtr->[$j]->[3] != $uFirst
	     || $allVertsPtr->[$j]->[4] != $vFirst)
	    {
		$hasUV = 1;
		last;
	    }
	}
    }

    my @minVerts = ( 999999, 999999, 999999, 999999, 999999);
    my @maxVerts = (-999999,-999999,-999999,-999999,-999999);

#    foreach $j (@{$group->{verts}}) {
#	my $i;
#	for ($i=0; $i<5; $i++) {
#	    my $val = $allVertsPtr->[$j]->[$i];
#	    $minVerts[$i] = $val if $val < $minVerts[$i];
#	    $maxVerts[$i] = $val if $val > $maxVerts[$i];
#	}
#    }

    # Use min/max in overall clump rather than just used parts, to make sure
    # the vertex joins with other subclumps are encoded the same way, to avoid
    # gaps.
    foreach $j (@$allVertsPtr) {
	my $i;
	for ($i=0; $i<5; $i++) {
	    my $val = $j->[$i];
	    $minVerts[$i] = $val if $val < $minVerts[$i];
	    $maxVerts[$i] = $val if $val > $maxVerts[$i];
	}
    }
#print "Min vals are $minVerts[0] $minVerts[1] $minVerts[2] $minVerts[3] $minVerts[4]\n";
#print "Max vals are $maxVerts[0] $maxVerts[1] $maxVerts[2] $maxVerts[3] $maxVerts[4]\n";

    my $numVerts = @{$group->{verts}};
    my $hasVertUV = 0;

    my $vEqualsZ = 1;
    my $vInvertY = 1;
    my $uEqualsX = 1;

    # Write out only the verts that we use.
    if ($hasUV) {
	my $flagVal = unpack("C", substr($$data, $uvflagPos, 1)) + 128;

	# Determine whether uv coding of vertices can be computed, or must be
	# stored.
	if ($numVerts > 0) {
	    if ($maxVerts[1] <= $minVerts[1]) {
		print "ERROR: Can't compute v with ymin,ymax=$minVerts[1],$maxVerts[1]\n";
#                exit 1;
	    }
	    if ($maxVerts[0] <= $minVerts[0]) {
		print "ERROR: Can't compute u with xmin,xmax=$minVerts[0],$maxVerts[0]\n";
 #               exit 1;
	    }
	}

	foreach $j (@{$group->{verts}}) {
	    my $vCode = encodeVal($allVertsPtr->[$j]->[4],
						$minVerts[4], $maxVerts[4]);
	    my $yCode = encodeVal($allVertsPtr->[$j]->[1],
					$minVerts[1], $maxVerts[1]);
	    my $zCode = encodeVal($allVertsPtr->[$j]->[2],
					$minVerts[2], $maxVerts[2]);
	    my $xCode = encodeVal($allVertsPtr->[$j]->[0],
					$minVerts[0], $maxVerts[0]);
	    my $uCode = encodeVal($allVertsPtr->[$j]->[3],
					    $minVerts[3], $maxVerts[3]);
	    if ($uEqualsX && ($uCode < $xCode-5 || $uCode > $xCode+5)) {
		#print "NOTE: uCode $uCode != xCode $xCode.\n";
		$uEqualsX = 0;
	    }
	    if ($vInvertY && ($vCode+$yCode < 250 || $vCode+$yCode > 260)) {
		#print "NOTE: vCode $vCode and yCode $yCode don't total 255.\n";
		$vInvertY = 0;
	    }
	    if ($vEqualsZ && ($vCode < $zCode-5 || $vCode > $zCode+5)) {
		#print "NOTE: vCode $vCode != zCode $zCode.\n";
		$vEqualsZ = 0;
	    }
	}

	$flagVal += 8 if $vEqualsZ;
	$flagVal += 4 if $vInvertY;
	$flagVal += 2 if $uEqualsX;

	substr($$data, $uvflagPos, 1) = pack "C", $flagVal;
    }
    
    my $beforeLen = length $$data;
    $$data .= pack("v", $numVerts);
    
    if ($numVerts > 0) {
	# Write min and max vert values.
	if ($hasUV) {
	    $$data .= packFloat($minVerts[4]) . packFloat($maxVerts[4]);
	}
	$$data .= packFloat($minVerts[1]) . packFloat($maxVerts[1])
		. packFloat($minVerts[2]) . packFloat($maxVerts[2])
		. packFloat($minVerts[0]) . packFloat($maxVerts[0]);
	$vertHeadBytes += 18;
	if ($hasUV) {
	    $$data .= packFloat($minVerts[3]) . packFloat($maxVerts[3]);
	    $vertHeadBytes += 12;
	}

	my $i;
	for ($i=0; $i<5; $i++) {
	    next if $i == 3 && (!$hasUV || $uEqualsX);
	    next if $i == 4 && (!$hasUV || $vEqualsZ || $vInvertY);

	    foreach $j (@{$group->{verts}}) {
		$$data .= pack("C", encodeVal($allVertsPtr->[$j]->[$i],
						$minVerts[$i], $maxVerts[$i]));
	    }
	}
    }
    $vertBytes += length($$data) - $beforeLen;

    # Write the tris.
    # Sort according to highest vertex in each triangle.

    my @tris = sort { compareTris(
				$group->{origToNewVert}->[$a->[0]],
				$group->{origToNewVert}->[$a->[1]],
				$group->{origToNewVert}->[$a->[2]],
				$group->{origToNewVert}->[$b->[0]],
				$group->{origToNewVert}->[$b->[1]],
				$group->{origToNewVert}->[$b->[2]]); }
			 @{$group->{tris}};

    my $numTris = @tris;
    $$data .= pack("v", $numTris);

    if ($numTris > 0) {
	my $firstTri = shift @tris;
	if ($group->{origToNewVert}->[$firstTri->[0]] != 0
	 || $group->{origToNewVert}->[$firstTri->[1]] != 1
	 || $group->{origToNewVert}->[$firstTri->[2]] != 2) {
	    my $v1 = $group->{origToNewVert}->[$firstTri->[0]];
	    my $v2 = $group->{origToNewVert}->[$firstTri->[1]];
	    my $v3 = $group->{origToNewVert}->[$firstTri->[2]];
	    print "ERROR: First tri wasn't 0 1 2, was $v1,$v2,$v3.\n";
	    exit -1;
	}
    }

    $$data .= compTris($group, \@tris);
}

sub incChildrenByte {
    ($data, $index) = @_;
    my $val = unpack("C", substr($$data, $index, 1));
    if ($val >= 255) {
	print "ERROR: More than 255 children.\n";
	exit -1;
    }
    substr($$data, $index, 1) = pack("C", 1+$val);
}

sub getPart {
    ($name) = @_;
    my $tag = $tags{$name};
    
    # See if part is already present.  It's an error if so.
    my $part;
    foreach $part (@partTag) {
	if ($part eq $tag) {
	    print "ERROR: part $name occurs twice.\n";
	    exit -1;
	}
    }
    
    $partTag[$numParts] = $tags{$name};
    return \$parts[$numParts++];
}
	
sub intensity {
    $_[0]->[0]*0.299 + $_[0]->[1]*0.587 + $_[0]->[2]*0.114;
}

# Append a single clump encoding for input clump $name to $parent.  If this
# is a part, add the additional part to @parts, with the $parent clump being
# just a placeholder.
#
sub doClump {
    my ($name, $parentData, $prevColor, $prevTexture) = @_;
    my ($xTrans, $yTrans, $zTrans) = (0, 0, 0);
    my $isPart = $labels{$name};
    my $data = $parentData;
    my $tag = $tags{$name};
    my $removeUV = 0;
    if ($isPart) {
	$data = getPart($name);
	if ($name eq "rtwrist" || $name eq "lfwrist"
	 || $name eq "rtankle" || $name eq "lfankle")
	{
	    $removeUV = 1;
	}
    } else {
	if ($tag eq "") {
	    if ($name ne "") {
		print "Note: Unrecognized clump $name.\n";
	    }
	} else {
	    print "Silent clump $name.\n";
	}
    }
    
    my @allVerts = ();
    my @vertEquiv = (); # null or index of preceding exact-match vert.
    my $uvflagPos;
    my $numChildPos;
    local $scale = $scale; # Allow local mods to enclosing scale value.
    
    # Set for one line after "Surface".
    my $intensity = "";
    
    # @groups has an entry for each separate color value within this clump.
    #
    # Each entry (group) is a hash holding the following references to arrays,
    # representing the vertex, triangle, and color status of that group:
    #
    #      color           r,g,b
    #      tris            triangles (each entry is a triple).
    #      verts           [our vertex index] == @allVerts index. 
    #      origToNewVert   [@allVerts index] == our vertex index.
    #
    # Vertex indices are origin 0.
    #
    my @groups = ();
    my $cur = "";
    
    while (<IN>) {
	chomp;
	my $orig = $_;
	
	if ($orig =~ /^\s*color\s+([-\d\.]+)\s+([-\d\.]+)\s+([-\d\.]+)\s*$/ix)
	{
	    my $red = 255*$1;
	    my $green = 255*$2;
	    my $blue = 255*$3;
	    if ($intensity ne "") {
		# Surface given, set color intensity to match.
		my $i = max(0.01, intensity([$1, $2, $3]));
		$red = min(255, $red*$intensity/$i);
		$green = min(255, $green*$intensity/$i);
		$blue = min(255, $blue*$intensity/$i);
		$intensity = "";
	    }

	    # Make new group if no existing one matches this color.
	    $prevColor = [$red, $green, $blue];
	    $cur = makeOrFindGroup(\@groups, $prevColor, $prevTexture);
	} elsif ($intensity ne "") {
	    print "Note: Surface but no color before:\n    $orig\n\n";
            print "Intensity $intensity Red $red Green $green Blue $blue\n";
            print "  -possible solution - place surface before color\n";
	    $intensity = "";
	} elsif ($orig =~ /^\s*texture\s+([^ ]+)\s*$/i) {
	    $prevTexture = lc($1);
	    $prevTexture = "" if $prevTexture eq "null";
	    $cur = makeOrFindGroup(\@groups, $prevColor, $prevTexture);
	} elsif ($orig =~ /^\s*quad\s+(\d+)\s+(\d+)\s+(\d+)\s+(\d+)\s*$/i) {
	    my ($v1, $v2, $v3, $v4) = ($vertEquiv[$1-1], $vertEquiv[$2-1],
					$vertEquiv[$3-1], $vertEquiv[$4-1]);
    
	    if ($cur eq "") {
		print "Note: clump $name has no color, using prev clump's.\n";
		$cur = makeOrFindGroup(\@groups, $prevColor, $prevTexture);
	    }
	    
	    if ($v1 == $v2 || $v2 == $v3 || $v1 == $v3) {
		print "WARNING: Removing degenerate tri $1,$2,$3 from $name.\n";
	    } else {
		$cur = pushTri($cur, \@groups, [$v1, $v2, $v3], scalar @allVerts);
	    }
	    if ($v1 == $v3 || $v3 == $v4 || $v1 == $v4) {
		print "WARNING: Removing degenerate tri $1,$3,$4 from $name.\n";
	    } else {
		$cur = pushTri($cur, \@groups, [$v1, $v3, $v4], scalar @allVerts);
	    }
	} elsif ($orig =~ /^\s*triangle\s+(\d+)\s+(\d+)\s+(\d+)\s*$/i) {
	    if ($cur eq "") {
		print "Note: clump $name has no color, using prev clump's.\n";
		$cur = makeOrFindGroup(\@groups, $prevColor, $prevTexture);
	    }
	    
	    my $v1, $v2, $v3;
	    
	    #if (0)
	    if ($swapZY)
	    {
	        ($v3, $v2, $v1) = ($vertEquiv[$1-1], $vertEquiv[$2-1], 
							$vertEquiv[$3-1]);
	    }
	    else
	    {
	        ($v1, $v2, $v3) = ($vertEquiv[$1-1], $vertEquiv[$2-1], 
							$vertEquiv[$3-1]);
	    }
	    if ($v1 == $v2 || $v2 == $v3 || $v1 == $v3) {
		print "WARNING: Removing degenerate tri $1,$2,$3 from $name.\n";
	    } else {
		$cur = pushTri($cur, \@groups, [$v1, $v2, $v3], scalar @allVerts);
	    }
	} elsif ($orig =~ /^\s*translate
				\s+([-\d\.]+)\s+([-\d\.]+)\s+([-\d\.]+)/ix)
	{
	    ($xTrans, $yTrans, $zTrans) = ($1*$scale, $2*$scale, $3*$scale);
	} elsif ($orig =~ /^\s*transform
		\s+([-\d\.]+)\s+([-\d\.]+)\s+([-\d\.]+)\s+([-\d\.]+)
		\s+([-\d\.]+)\s+([-\d\.]+)\s+([-\d\.]+)\s+([-\d\.]+)
		\s+([-\d\.]+)\s+([-\d\.]+)\s+([-\d\.]+)\s+([-\d\.]+)
		\s+([-\d\.]+)\s+([-\d\.]+)\s+([-\d\.]+)\s+([-\d\.]+)\s*/ix) 
	{
	    $scale *= $1 if $1 != 1;
	    ($xTrans, $yTrans, $zTrans) = ($13*$scale, $14*$scale,$15*$scale);
	} elsif ($orig =~ /^\s*(clumpbegin.*)$/i) {
	    # The translation value has been read by now, so finish writing
	    # the header for this clump.
	    
	    if ($uvflagPos) {
		print "Note: Unlabeled subclump in $name\n";
	    }

	    if ($unexplode) {
		# Halve translation values from this converter.
		$xTrans /= 2;
		$yTrans /= 2;
		$zTrans /= 2;
	    }
	    
	    if ($swapZY)
	    {
	        my $tmpX = $xTrans;
	        my $tmpY = $yTrans;
	        my $tmpZ = $zTrans;
	        $xTrans = $tmpX * -1;
	        $yTrans = $tmpZ;
	        $zTrans = $tmpY;
	    }
	    
	    # Generate placeholder in parent.
	    if ($isPart && $parentData ne "") {
		$$parentData .= pack("C", 128 + $tag);
		$$parentData .= pack("C", 64*($xTrans!=0)
				+ 32*($yTrans!=0) + 16*($zTrans!=0));
		$$parentData .= packFloat($xTrans) if ($xTrans != 0);
		$$parentData .= packFloat($yTrans) if ($yTrans != 0);
		$$parentData .= packFloat($zTrans) if ($zTrans != 0);
		$xTrans = 0;
		$yTrans = 0;
		$zTrans = 0;
	    }
	    
	    $$data .= pack("C", $tag);
	    $uvflagPos = length($$data);
	    $$data .= pack("C", 64*($xTrans!=0) 
					+ 32*($yTrans!=0) + 16*($zTrans!=0));
	    $$data .= packFloat($xTrans) if ($xTrans != 0);
	    $$data .= packFloat($yTrans) if ($yTrans != 0);
	    $$data .= packFloat($zTrans) if ($zTrans != 0);
	} elsif ($orig =~ /^\s*vertex(ext)?
				\s+([-\d\.]+)\s+([-\d\.]+)\s+([-\d\.]+)\s*
				(UV\s+([-\d\.]+)\s+([-\d\.]+))*\s*$/ix) 
	{
	    # If vertex identical to last, mark it so.
	    my $newVert;
	    
	    if ($swapZY)
	    {
	        $newVert = [$2*$scale * -1, $4*$scale, $3*$scale, $6, $7];
	    }
	    else
	    {
	        $newVert = [$2*$scale, $3*$scale, $4*$scale, $6, $7];
	    }
	    
	    # Remove UV from hands and feet.
	    if ($removeUV) {
		$newVert->[3] = "";
		$newVert->[4] = "";
	    }
	    
	    $vertEquiv[@allVerts] = @allVerts;
	    if (@allVerts > 0) {
		# Check all verts for duplicates when removing UV.
		my $i = $removeUV ? 0 : (@allVerts - 1);
		
		for (; $i < @allVerts; $i++) {
		    my $lastVert = $allVerts[$i];
		    if ($lastVert->[0] == $newVert->[0]
		     && $lastVert->[1] == $newVert->[1]
		     && $lastVert->[2] == $newVert->[2]
		     && $lastVert->[3] == $newVert->[3]
		     && $lastVert->[4] == $newVert->[4])
		    {
			$vertEquiv[@allVerts] = $vertEquiv[$i];
			last;
		    }
		}
	    }
	    push @allVerts, $newVert;
	} elsif ($orig =~ /^\s*surface
			    \s+([-\d\.]+)\s+([-\d\.]+)\s+([-\d\.]+)\s*$/ix)
	{
	    # Surface 0.65 0.22 0 translates into full intensity.
	    # Surface 0.3 0.1 0 translates into near-zero intensity.
	    $intensity = max(0, min(1, ($1+$2 - 0.27) / 0.6));
	} elsif ($orig =~ /^\s*(transform(end)|#\s*([^ ]+))/i) {
	    # Skip our lead-in transformbegin.
	    next if length($2) == 5 && !$uvflagPos;  
		
	    my $isTrans = $2;
	    my $childName = $3;
	    
	    if ($numChildPos) {
		if ($cur ne "") {
		    print "ERROR: polygons after subclumps\n";
		    exit -1;
		}
	    } else {
		# End of polygon part of clump, write out verts and tris.

		# Remove any groups that have no tris.
		my @usedGroups = ();
		my $g;
		foreach $g (@groups) {
		    push @usedGroups, $g if scalar @{$g->{tris}} != 0;
		}
		# Sort the groups so that those with textures come first
		# (in alphabetical order), then bright colors,
		# then groups with more polys.
		@usedGroups = reverse sort {
			(((((((($a->{texture} ne "") <=> ($b->{texture} ne ""))
		       or ($b->{texture} cmp $a->{texture}))
		       or (intensity($a->{color}) <=> intensity($b->{color})))
		       or ($a->{color}->[0] <=> $b->{color}->[0]))
		       or ($a->{color}->[1] <=> $b->{color}->[1]))
		       or ($a->{color}->[2] <=> $b->{color}->[2]))
		       or (@{$a->{tris}} <=> @{$b->{tris}}));
		    } @usedGroups;

		# First write the clump's primary verts and tris.
		if (@usedGroups == 0) {
		    print "Note: Empty clump $name\n";
		    $$data .= pack("CC", 0, 0);
		} else {
		    $g = shift @usedGroups;
		    writeColorVertsAndTris($data, $g, $uvflagPos, \@allVerts);
		}

		$numChildPos = length($$data);
		$$data .= pack("C", scalar @usedGroups);

		# Write subsidiary clumps.
		foreach $g (@usedGroups) {
		    # Write new clump header. No tag, no translation.
		    $$data .= pack("C", 0);
		    $uvflagPos = length($$data);
		    $$data .= pack("C", 0);
		    
		    writeColorVertsAndTris($data, $g, $uvflagPos, \@allVerts);
		    $$data .= pack("C", 0);
		}
		
		@groups = ();
		$cur = "";
	    }
	    
	    if ($isTrans) {   # Transformbegin or transformend
		return if length($isTrans) == 3;  # Done if transformend.
		
		# An unlabeled child clump.
		print "Note: Unlabeled subclump in $name\n";
	    }
	    
	    # Add dummy parts to fill in missing parts of the limb hierarchy.
	    if ($name eq "pelvis" && ($childName eq "head"
				|| $childName eq "neck"
				|| $childName eq "lfshoulder"
				|| $childName eq "rtshoulder"))
	    {
		if (!$backData) {
		    my $backTag = $tags{"back"}, 
		
		    # Attach dummy back to pelvis.
		    incChildrenByte($data, $numChildPos);
		    $$data .= pack "CC", $backTag+128, 0;

		    # Make dummy back.
		    $backData = getPart("back");
		    
		    # Dummy back has only one placeholder clump -- for now.
		    # tag, flag, rgb, numVerts, numTris, numChildren.
		    $$backData .= pack "CCCCCvvC", $backTag, 0, 0, 0, 0,
						    0, 0, 1;
		    $backNumChildPos = length($$backData)-1;
		} else {
		    incChildrenByte($backData, $backNumChildPos);
		}
		
		if ($childName eq "head") {
		    my $neckTag = $tags{"neck"}; # 70
		
		    # Make dummy neck.
		    my $neckData = getPart("neck");

		    # Dummy neck has one child clump -- the head placeholder.
		    $$neckData .= pack "CCCCCvvC", $neckTag, 0, 0, 0, 0,
							0, 0, 1;
		    my $neckLen = length($$neckData);
		    doClump($childName, $neckData, $prevColor);
		    
		    # Attach dummy neck to back.
		    $$backData .= pack "C", $neckTag+128;

		    # Move translation from neck's head placeholder to back's
		    # neck placeholder.
		    $$backData .= substr($$neckData, $neckLen+1);
		    substr($$neckData, $neckLen+1) = pack("C", 0);
		} else {
		    # Attach to dummy back.
		    doClump($childName, $backData, $prevColor);
		}
	    } elsif ($name eq "back" && $childName eq "head") {
		# Use bogus tag for neck so won't get bogus movement data.
		my $neckTag = $tags{"neck"}; # 70
		
		# Make dummy neck.
		my $neckData = getPart("neck");

		# Dummy neck has one child clump -- the head placeholder.
		$$neckData .= pack "CCCCCvvC", $neckTag, 0, 0, 0, 0, 0, 0, 1;
		
		my $neckLen = length($$neckData);
						    
		doClump($childName, $neckData, $prevColor);
		
		# Attach dummy neck to back.
		incChildrenByte($data, $numChildPos);
		$$data .= pack "C", $neckTag+128;

		# Move translation from neck's head placeholder to back's neck
		# placeholder.
		$$data .= substr($$neckData, $neckLen+1);
		substr($$neckData, $neckLen+1) = pack("C", 0);
	    } else {
		incChildrenByte($data, $numChildPos);
		doClump($childName, $data, $prevColor);
	    }
	}
    }
}

my $nextFileIndex = 0;
RWXFILE: while ($nextFileIndex < @ARGV) {
    if ($filesInPairs) {
	$infile = $ARGV[$nextFileIndex];
	$outfile = $ARGV[$nextFileIndex+1];
	$nextFileIndex += 2;
    } else {
	my $file = $ARGV[$nextFileIndex];
	if ($file =~ /^(.*)\.rwx$/i) {
	    $file = $1;
	}
	$infile = $file . ".rwx";
	$outfile = $file . ".bod";
	$nextFileIndex += 1;
    }
    
    #ignore command-line parameters
    if (index($infile, "-") == 0)
    {
        next RWXFILE;
    }
    
    # The tag values for each part.
    @partTag = ();

    # The byte strings the clump data for each part.
    @parts = ();
    $numParts = 0;

    $triBytes = 0;
    $vertHeadBytes = 0;
    $vertBytes = 0;
    $backData = "";

    $is3ds2rwx = 0;


	my $index ;
	my $n ;
	my $numbits ;
	my $numsections ;
	my $size ;
	my $buffer ;
	my $beginning ;
	my $firstProto ;
	my $section ;
	my $text ;

	my @info ;
	my @protobits ;
	my @sectionbits ;
	my @transformbits ;

	# INPUT STAGE

	open IN, $infile or die "could not open $infile\n" ;
	open TEMP, ">tempfile.999"
		or die "could not create a temporary file\n" ;

	@info = stat IN ;
	$size = $info[7] ;

	read IN, $buffer, $size ;

	# PROTO BREAK STAGE

	@protobits = split /\s*ProtoEnd\n/, $buffer ;

	$numbits = scalar @protobits ;

	($beginning, $firstProto) = split /\s*ProtoBegin/, $protobits[0] ;

	$protobits[0] = $firstProto ;
	$index = index $protobits[0],"\n" ;
 	$protobits[0] = substr $protobits[0], $index ;

	# SECTION BREAK STAGE

	@sectionbits = split /\s*ProtoInstance/, $protobits[$numbits-1] ;

	$numsections = scalar @sectionbits ;

	if( $numbits != $numsections )
	{
		printf "WARNING: ProtoBegin's do not match ProtoInstances\n" ;
		printf "Probable Invalid .RWX File.\n" ;

		# Note: this is a HACK, You should be able to match up each
		# ProtoBegin with only those ProtoInstance lines that use the
		# same Tag.  For now, I only have files where they are equal,
		# so I am not worring about it, but there may come a time....
	}

	# PROTO/SECTION COLLECTION STAGE

	$text = $beginning ;
	$text = $text . "$sectionbits[0]\n" ;

	for( $n = 0; $n < $numsections-1 ; $n++ )
	{
		$protobits[$n] =~ s/^\s*ProtoBegin\s+[^ ]+\s*\n// ;
		$index = index $sectionbits[$n+1],"\n" ;
	 	$section = substr $sectionbits[$n+1], $index ;
		$text = $text . "$protobits[$n]\n" ;
	 	$text = $text . "$section\n" ;
	}

	# COMMENT/TRANSFORM SWAP

	@transformbits = split /TransformBegin/, $text ;
	$numbits = scalar @transformbits ;

	# we now have: Begin, extra, extra

	printf TEMP "$transformbits[$0]" ;

	for( $n = 1; $n < $numbits ; $n++ )
	{
		my @temp = split /(#.*\n)/, $transformbits[$n] ;  # extra
		my $bits = scalar @temp ;
		if( $bits != 3 )
		{
			print "WARNING: found $bits comment fragments\n $transformbits[$n]\n" ;
			print "Possible corrupted RWX file\n" ;
		}
		printf TEMP "$temp[1]" ;
		printf TEMP "TransformBegin\n" ;
		printf TEMP "$temp[0]" ;
		printf TEMP "$temp[2]" ;
	}

	close TEMP ;

    if (!open(IN, "tempfile.999")) {
	print "ERROR: couldn't open a required temporary file!\n";
	exit -1;
    }

    print "Converting $infile to $outfile.\n";

    local $scale = 1;

    # Scan to the ModelBegin.
    while (<IN>) {
	$is3ds2rwx = 1 if /^#.*by 3ds2rwx/;
	last if /^ModelBegin/i;
    }

    # Scan to first label in the model, which must be pelvis.
    while (<IN>) {
	chomp;

	if (/^\s*#\s*([^ ]+)/) {
	    if ($1 ne "pelvis") {
		print "Note: first label ($1) wasn't pelvis.\n";
	    }
	    
	    doClump($1, "");
	    
	    # Write file out: first dictionary of parts, then the parts.
	    if (!open(OUT, ">$outfile")) {
		print "ERROR: couldn't open $outfile!\n";
		exit -1;
	    }
	    
	    binmode OUT;
	    
	    print OUT pack("C", 1);   # version number.
	    print OUT pack("C", int($numParts));   # number of parts.
	    my $i;
	    my $offset = 0;
	    for ($i=0; $i<$numParts; $i++) {
		print OUT pack("CS", $partTag[$i], $offset);
		$offset += length($parts[$i]);
	    }
	    for ($i=0; $i<$numParts; $i++) {
		print OUT $parts[$i];
	    }
#print "Tri $triBytes, $vertHeadBytes vertHead, $vertBytes vert bytes\n";
	    close OUT;
	    last;
	}
    }
    close IN;

	unlink "tempfile.999" ;
}
