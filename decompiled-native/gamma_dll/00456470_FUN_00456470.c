// 00456470 FUN_00456470 [Global]
// program: gamma.dll

/* WARNING: Removing unreachable block (ram,0x00456592) */
/* WARNING: Removing unreachable block (ram,0x00456574) */
/* WARNING: Removing unreachable block (ram,0x00456556) */
/* WARNING: Removing unreachable block (ram,0x00456538) */
/* WARNING: Removing unreachable block (ram,0x0045651a) */
/* WARNING: Removing unreachable block (ram,0x004564fc) */
/* WARNING: Removing unreachable block (ram,0x004564d1) */
/* WARNING: Removing unreachable block (ram,0x004564bf) */
/* WARNING: Removing unreachable block (ram,0x00456499) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00456470(void)

{
  int *piVar1;
  undefined4 *puVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  byte in_CF;
  byte in_PF;
  byte in_AF;
  byte in_ZF;
  byte in_SF;
  byte in_TF;
  byte in_IF;
  byte in_OF;
  byte in_NT;
  byte in_AC;
  byte in_VIF;
  byte in_VIP;
  byte in_ID;
  uint uVar6;
  
  uVar6 = (uint)(in_NT & 1) * 0x4000 | (uint)(in_OF & 1) * 0x800 | (uint)(in_IF & 1) * 0x200 |
          (uint)(in_TF & 1) * 0x100 | (uint)(in_SF & 1) * 0x80 | (uint)(in_ZF & 1) * 0x40 |
          (uint)(in_AF & 1) * 0x10 | (uint)(in_PF & 1) * 4 | (uint)(in_CF & 1) |
          (uint)(in_ID & 1) * 0x200000 | (uint)(in_VIP & 1) * 0x100000 |
          (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000;
  uVar5 = uVar6 ^ 0x200000;
  if (((uint)((uVar5 & 0x4000) != 0) * 0x4000 | (uint)((uVar5 & 0x800) != 0) * 0x800 |
       (uint)((uVar5 & 0x200) != 0) * 0x200 | (uint)((uVar5 & 0x100) != 0) * 0x100 |
       (uint)((uVar5 & 0x80) != 0) * 0x80 | (uint)((uVar5 & 0x40) != 0) * 0x40 |
       (uint)((uVar5 & 0x10) != 0) * 0x10 | (uint)((uVar5 & 4) != 0) * 4 | (uint)((uVar5 & 1) != 0)
       | (uint)((uVar5 & 0x200000) != 0) * 0x200000 | (uint)((uVar5 & 0x40000) != 0) * 0x40000) ==
      uVar6) {
    uVar5 = 0xffffffff;
  }
  else {
    piVar1 = (int *)cpuid_basic_info(0);
    _DAT_0049ea88 = piVar1[1];
    _DAT_0049ea8c = piVar1[2];
    _DAT_0049ea90 = piVar1[3];
    uVar5 = 1;
    uVar6 = _DAT_0049ea8c;
    if (*piVar1 != 0) {
      puVar2 = (undefined4 *)cpuid_Version_info(1);
      DAT_0049ead0 = *puVar2;
      DAT_0049eac8 = puVar2[2];
      puVar3 = (uint *)cpuid(0x80000000);
      uVar5 = *puVar3;
      uVar6 = puVar3[2];
      if (0x80000000 < uVar5) {
        if (0x80000003 < uVar5) {
          if (0x80000004 < uVar5) {
            if (0x80000005 < uVar5) {
              puVar2 = (undefined4 *)cpuid(0x80000006);
              DAT_0049eae4 = *puVar2;
              DAT_0049eae8 = puVar2[1];
              _DAT_0049eaf0 = puVar2[2];
              DAT_0049eaec = puVar2[3];
            }
            puVar2 = (undefined4 *)cpuid(0x80000005);
            DAT_0049ead4 = *puVar2;
            DAT_0049ead8 = puVar2[1];
            DAT_0049eae0 = puVar2[2];
            DAT_0049eadc = puVar2[3];
          }
          puVar2 = (undefined4 *)cpuid_brand_part1_info(0x80000002);
          _DAT_0049ea98 = *puVar2;
          _DAT_0049ea9c = puVar2[1];
          _DAT_0049eaa4 = puVar2[2];
          _DAT_0049eaa0 = puVar2[3];
          puVar2 = (undefined4 *)cpuid_brand_part2_info(0x80000003);
          _DAT_0049eaa8 = *puVar2;
          _DAT_0049eaac = puVar2[1];
          _DAT_0049eab4 = puVar2[2];
          _DAT_0049eab0 = puVar2[3];
          puVar2 = (undefined4 *)cpuid_brand_part3_info(0x80000004);
          _DAT_0049eab8 = *puVar2;
          _DAT_0049eabc = puVar2[1];
          _DAT_0049eac4 = puVar2[2];
          _DAT_0049eac0 = puVar2[3];
        }
        iVar4 = cpuid(0x80000001);
        uVar6 = *(uint *)(iVar4 + 8);
        uVar5 = 1;
        DAT_0049eacc = uVar6;
      }
    }
  }
  return CONCAT44(uVar6,uVar5);
}


