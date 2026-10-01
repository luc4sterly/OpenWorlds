// 100060b0 FUN_100060b0 [Global]
// program: rwdlmd21.dll

/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0x10006230) */
/* WARNING: Removing unreachable block (ram,0x100061f4) */
/* WARNING: Removing unreachable block (ram,0x100060f2) */
/* WARNING: Removing unreachable block (ram,0x10006131) */

undefined4 FUN_100060b0(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  ushort uVar4;
  uint uVar5;
  int iVar6;
  byte in_AF;
  byte in_TF;
  byte in_IF;
  byte in_NT;
  byte in_AC;
  byte in_VIF;
  byte in_VIP;
  byte in_ID;
  uint uVar7;
  uint uVar8;
  char local_2c [12];
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  undefined4 local_14;
  ushort local_a;
  short local_8;
  
  uVar1 = (uint)((in_NT & 1) != 0);
  uVar8 = (uint)((in_IF & 1) != 0);
  uVar2 = (uint)((in_TF & 1) != 0);
  uVar3 = (uint)((in_AF & 1) != 0);
  uVar7 = uVar1 * 0x4000 | uVar8 * 0x200 | uVar2 * 0x100 |
          (uint)((short)(ushort)&stack0xffffffcc < 0) * 0x80 |
          (uint)(((uint)&stack0xffffffcc & 0xfffc) == 0) * 0x40 | uVar3 * 0x10 |
          (uint)((POPCOUNT((ushort)&stack0xffffffcc & 0xfc) & 1U) == 0) * 4 |
          (uint)(in_ID & 1) * 0x200000 | (uint)(in_VIP & 1) * 0x100000 |
          (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000;
  uVar5 = uVar7 ^ 0x40000;
  local_a = 3;
  if (((uint)((uVar5 & 0x4000) != 0) * 0x4000 | (uint)((uVar5 & 0x200) != 0) * 0x200 |
       (uint)((uVar5 & 0x100) != 0) * 0x100 | (uint)((uVar5 & 0x80) != 0) * 0x80 |
       (uint)((uVar5 & 0x40) != 0) * 0x40 | (uint)((uVar5 & 0x10) != 0) * 0x10 |
       (uint)((uVar5 & 4) != 0) * 4 | (uint)((uVar5 & 0x200000) != 0) * 0x200000 |
      (uint)((uVar5 & 0x40000) != 0) * 0x40000) != uVar7) {
    local_a = 0xffff;
  }
  iVar6 = CONCAT22((short)((uint)&stack0xffffffcc >> 0x10),(short)&stack0xffffffcc);
  uVar4 = local_a - 3;
  if (uVar4 == 0) {
    return 0;
  }
  local_8 = 4;
  *(uint *)(iVar6 + -4) =
       (uint)(uVar1 != 0) * 0x4000 | (uint)SBORROW2(local_a,3) * 0x800 | (uint)(uVar8 != 0) * 0x200
       | (uint)(uVar2 != 0) * 0x100 | (uint)((short)uVar4 < 0) * 0x80 | (uint)(uVar3 != 0) * 0x10 |
       (uint)((POPCOUNT(uVar4 & 0xff) & 1U) == 0) * 4 | (uint)(local_a < 3) |
       (uint)((in_ID & 1) != 0) * 0x200000 | (uint)((in_AC & 1) != 0) * 0x40000;
  uVar1 = *(uint *)(iVar6 + -4);
  *(uint *)(iVar6 + -4) = uVar1 ^ 0x200000;
  uVar8 = *(uint *)(iVar6 + -4);
  *(uint *)(iVar6 + -4) =
       (uint)((uVar8 & 0x4000) != 0) * 0x4000 | (uint)((uVar8 & 0x800) != 0) * 0x800 |
       (uint)((uVar8 & 0x400) != 0) * 0x400 | (uint)((uVar8 & 0x200) != 0) * 0x200 |
       (uint)((uVar8 & 0x100) != 0) * 0x100 | (uint)((uVar8 & 0x80) != 0) * 0x80 |
       (uint)((uVar8 & 0x40) != 0) * 0x40 | (uint)((uVar8 & 0x10) != 0) * 0x10 |
       (uint)((uVar8 & 4) != 0) * 4 | (uint)((uVar8 & 1) != 0) |
       (uint)((uVar8 & 0x200000) != 0) * 0x200000 | (uint)((uVar8 & 0x40000) != 0) * 0x40000;
  if (*(uint *)(iVar6 + -4) != uVar1) {
    local_8 = -1;
  }
  if (local_8 != 4) {
    local_14 = 0xffffffff;
    local_2c[0] = s_GenuineIntel_100871d4[0];
    local_2c[1] = s_GenuineIntel_100871d4[1];
    local_2c[2] = s_GenuineIntel_100871d4[2];
    local_2c[3] = s_GenuineIntel_100871d4[3];
    local_2c[4] = s_GenuineIntel_100871d4[4];
    local_2c[5] = s_GenuineIntel_100871d4[5];
    local_2c[6] = s_GenuineIntel_100871d4[6];
    local_2c[7] = s_GenuineIntel_100871d4[7];
    local_2c[8] = s_GenuineIntel_100871d4[8];
    local_2c[9] = s_GenuineIntel_100871d4[9];
    local_2c[10] = s_GenuineIntel_100871d4[10];
    local_2c[0xb] = s_GenuineIntel_100871d4[0xb];
    iVar6 = cpuid_basic_info(0);
    local_18 = *(int *)(iVar6 + 0xc);
    local_20 = *(undefined4 *)(iVar6 + 4);
    local_1c = *(undefined4 *)(iVar6 + 8);
    iVar6 = 0;
    do {
      if (local_2c[iVar6] != *(char *)((int)&local_20 + iVar6)) {
        local_18 = 0;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < 0xc);
    if (local_18 == 0) {
      return 0xffffffff;
    }
    if (0 < iVar6) {
      iVar6 = cpuid_Version_info(1);
      local_14 = *(undefined4 *)(iVar6 + 8);
    }
    return local_14;
  }
  return 0;
}


