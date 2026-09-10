@echo off
if exist %0 goto fullpath
perl -S -x %0.bat %1 %2 %3 %4 %5 %6 %7 %8 %9
goto endofperl
:fullpath
perl -x %0 %1 %2 %3 %4 %5 %6 %7 %8 %9
goto endofperl

#!perl

if (@ARGV != 1) {
    print "USAGE: $0 file\n";
    print "  example: $0 aura  <-- makes aura.rwx from aura.bod\n";
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

sub getOne {
    $offset++;
    return getc IN;
}

sub getByte {
    return unpack "C", getOne();
}

#
# Write out a .bo file in place of this .bod.  See rwxtobod.bat for doc on
# the bod file format.  The bo file is a human-readable form of the bod,
# somewhat like rwx, for use in debugging rwxtobod.bat.
#

$file = $ARGV[0];

if (!open(IN, "$file.bod")) {
    print "ERROR: couldn't open $file.bod!\n";
    exit;
}
binmode IN;

print "Converting $file.bod to $file.bo.\n";

# Write file out: first the header.
if (!open(OUT, ">$file.bo")) {
    print "ERROR: couldn't open $file.bo!\n";
    exit;
}

print OUT "Version ", getByte(), "\n";
my $numParts = getByte();

print OUT "$numParts parts:\n";

# Print a table of the part offsets.
my @parts;
for ($p=0; $p < $numParts; $p++) {
    my $tag = getByte();
    my $entry = getOne();
    $entry .= getOne();
    my $o = unpack "S", $entry;
    print OUT "  $tag  $o\n";
}

# Print the nested clump structure for each part.
$offset = 0;

sub getFloat {
    my $entry = pack "C", 0;
    $entry .= getOne();
    $entry .= getOne();
    $entry .= getOne();
    return unpack "f", $entry;
}

sub getShort {
    my $entry = getOne();
    $entry .= getOne();
    return unpack "v", $entry;
}

@labels = (
    "pelvis",
    "back",
    "neck",
    "head",
    "rtsternum",
    "rtshoulder",
    "rtelbow",
    "rtwrist",
    "rtfingers",
    "lfsternum",
    "lfshoulder",
    "lfelbow",
    "lfwrist",
    "lffingers",
    "rthip",
    "rtknee",
    "rtankle",
    "rttoes",
    "lfhip",
    "lfknee",
    "lfankle",
    "lftoes",
    "back2",
    "back3",
    "mouth",
    "nose",
    "lfear",
    "rtear",
    "tail1",
    "tail2",
    "tail3",
    "tail4"
);

my $nextBit, $partialByte;
sub getBits {
    my $cap = $_[0];
    my $val = 0;
    my $bit;
    for ($bit=1; $bit < $cap; $bit <<= 1) {
	$partialByte = getByte() if $nextBit == 1;
	$val += $bit if $partialByte & $nextBit;
	$nextBit = 1 if ($nextBit <<= 1) == 256;
    }
    return $val;
}
    
sub printClump {
    my ($blanks) = @_;
    my $tag = getByte();
    
    if ($tag != 0) {
	print OUT "$blanks  Tag [", $labels[($tag&127)-1], "] ",
	    ($tag>=128? "(placeholder) ":""), ($tag&127), "\n";
    }
    my $flag = getByte();
    
    if ($flag & (64+32+16)) {
	my ($x, $y, $z) = (0, 0, 0);
	$x = getFloat() if $flag & 64;
	$y = getFloat() if $flag & 32;
	$z = getFloat() if $flag & 16;
	printf OUT "$blanks  Translate %1.6f %1.6f %1.6f\n", $x, $y, $z;
    }
    
    if (($tag & 128) == 0) {
	my $r = getByte()/255;
	my $g = getByte()/255;
	my $b = getByte()/255;
	printf OUT "$blanks  Color %1.3f %1.3f %1.3f\n", $r, $g, $b;
	
	my $i;
	my $numVerts = getShort();
	if ($numVerts > 0) {
	    my $vMin = 0, $vMax = 0;
	    if ($flag & 128) {
		$vMin = getFloat();
		$vMax = getFloat();
	    }
	    my $yMin = getFloat();
	    my $yMax = getFloat();
	    my $zMin = getFloat();
	    my $zMax = getFloat();
	    my $xMin = getFloat();
	    my $xMax = getFloat();
	    my $uMin = 0, $uMax = 0;
	    if ($flag & 128) {
		$uMin = getFloat();
		$uMax = getFloat();
	    }
	    # Read vert columns.
	    my @bytes = ([], [], [], [], []);
	    my $v;
	    for ($v=0; $v<5; $v++) {
		next if $v == 3 && (!($flag & 128) || ($flag & 2));
		next if $v == 4 && (!($flag & 128) || ($flag & 12));

		for ($i=0; $i<$numVerts; $i++) {
		    $bytes[$v]->[$i] = getByte();
		}
	    }

	    for ($i=0; $i<$numVerts; $i++) {
		my $yByte = $bytes[1]->[$i];
		my $zByte = $bytes[2]->[$i];
		my $xByte = $bytes[0]->[$i];

		my $y = $yByte * ($yMax - $yMin) / 255 + $yMin;
		my $z = $zByte * ($zMax - $zMin) / 255 + $zMin;
		my $x = $xByte * ($xMax - $xMin) / 255 + $xMin;
		my $u = 0;
		if ($flag & 128) {
		    if ($flag & 2) {
			$u = $xByte * ($uMax - $uMin) / 255 + $uMin;
		    } else {
			$u = $bytes[3]->[$i] * ($uMax - $uMin) / 255 + $uMin;
		    }
		    if ($flag & 8) {
			$v = $zByte * ($vMax - $vMin) / 255 + $vMin;
		    } elsif ($flag & 4) {
			$v = (255-$yByte) * ($vMax - $vMin) / 255 + $vMin;
		    } else {
			$v = $bytes[4]->[$i] * ($vMax - $vMin) / 255 + $vMin;
		    }
		    printf OUT
			"%s  Vertex %d: %1.6f %1.6f %1.6f UV %1.3f %1.3f\n",
			$blanks, $i+1, $x, $y, $z, $u, $v;
		} else {
		    printf OUT
			"%s  Vertex %d: %1.6f %1.6f %1.6f\n",
			$blanks, $i+1, $x, $y, $z;
		}
	    }
	}
	
	my $numTris = getShort();
	if ($numTris > 0) {
	    print OUT "$blanks  Triangle 1 2 3\n";
	}

	$nextBit = 1;
	my $highest = 2;
	for ($i=1; $i<$numTris; $i++) {
	    my $p1 = $highest + getBits(2);
	    my $cap = $highest + 4;
	    my $p2 = $highest - getBits($cap);
	    $p2 += $cap if $p2 < 0;
	    my $p3 = 0;
	    if ($p1 != $p2) {
		$p3 = $highest - getBits($cap);
		$p3 += $cap if $p3 < 0;
	    
		if ($p1+$p2+$p3 > 0) {
		    print OUT "$blanks  Triangle " . ($p1+1) . " "
				    . ($p2+1) . " " . ($p3+1) . "\n";

		    if ($p1 < 0 || $p1 >= $numVerts
		     || $p2 < 0 || $p2 >= $numVerts
		     || $p3 < 0 || $p3 >= $numVerts) {
			print "ERROR: Triangle has out-of-range vertex.\n";
			print OUT "ERROR: Triangle has out-of-range vertex.\n";
		    }
		} else {
		    print "ERROR: Degenerate triangle.\n";
		}
	    } else {
		print "Skipping highest $p1.\n";
		$i--;
	    }
	    $highest = max($p1, $p2, $p3);
	}
	
	my $numClumps = getByte();
	for ($i=0; $i<$numClumps; $i++) {
	    print OUT "$blanks  Clump $i:\n";
	    printClump($blanks . '  ');
	}
    }
}

print OUT "\nThe Parts:\n";
for ($p=0; $p < $numParts; $p++) {
    print OUT " Part $p at offset $offset:\n";
    printClump("");
}

__END__
:endofperl
