// 0044e570 FUN_0044e570 [Global]
// program: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_0044e570(undefined4 param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)FUN_0044e130();
  EnterCriticalSection(lpCriticalSection);
  DAT_0049fe0c = DAT_0049fe0c + -1;
  if (DAT_0049fe0c == 0) {
    FUN_00403ac0(0x49eda8);
    FUN_00403ac0(0x49ed60);
    FUN_00403ac0(0x49ed18);
    DAT_0049f9b0[0xf] = (int)&DAT_0049f9b8 - (int)DAT_0049f9b0;
    _DAT_0049f9ac = &PTR_LAB_0046f358;
    *DAT_0049f9b0 = &PTR_LAB_0046f364;
    DAT_0049f9b0[0xf] = (int)&DAT_0049f9b8 - (int)DAT_0049f9b0;
    _DAT_0049f9b8 = &PTR_LAB_0046f34c;
    FUN_00454d40((undefined4 *)&DAT_0049f9b8);
    DAT_0049edac[0xf] = (int)&DAT_0049edb0 - (int)DAT_0049edac;
    _DAT_0049eda8 = &PTR_LAB_00480fd4;
    *DAT_0049edac = &PTR_LAB_00480fe0;
    DAT_0049edac[0xf] = (int)&DAT_0049edb0 - (int)DAT_0049edac;
    _DAT_0049edb0 = &PTR_LAB_0046f34c;
    FUN_00454d40((undefined4 *)&DAT_0049edb0);
    DAT_0049ed64[0xf] = (int)&DAT_0049ed68 - (int)DAT_0049ed64;
    _DAT_0049ed60 = &PTR_LAB_00480fd4;
    *DAT_0049ed64 = &PTR_LAB_00480fe0;
    DAT_0049ed64[0xf] = (int)&DAT_0049ed68 - (int)DAT_0049ed64;
    _DAT_0049ed68 = &PTR_LAB_0046f34c;
    FUN_00454d40((undefined4 *)&DAT_0049ed68);
    DAT_0049ed1c[0xf] = (int)&DAT_0049ed20 - (int)DAT_0049ed1c;
    _DAT_0049ed18 = &PTR_LAB_00480fd4;
    *DAT_0049ed1c = &PTR_LAB_00480fe0;
    DAT_0049ed1c[0xf] = (int)&DAT_0049ed20 - (int)DAT_0049ed1c;
    _DAT_0049ed20 = &PTR_LAB_0046f34c;
    FUN_00454d40((undefined4 *)&DAT_0049ed20);
    FUN_0044f000(0x49f2b8);
    FUN_0044f000(0x49f348);
    FUN_0044f000(0x49f300);
    DAT_0049fa18[0xf] = (int)&DAT_0049fa20 - (int)DAT_0049fa18;
    _DAT_0049fa14 = &PTR_LAB_00480fbc;
    *DAT_0049fa18 = &PTR_LAB_00480fc8;
    DAT_0049fa18[0xf] = (int)&DAT_0049fa20 - (int)DAT_0049fa18;
    _DAT_0049fa20 = &PTR_LAB_00480fb0;
    FUN_00454d40((undefined4 *)&DAT_0049fa20);
    DAT_0049f2bc[0xf] = (int)&DAT_0049f2c0 - (int)DAT_0049f2bc;
    _DAT_0049f2b8 = &PTR_LAB_00480f98;
    *DAT_0049f2bc = &PTR_LAB_00480fa4;
    DAT_0049f2bc[0xf] = (int)&DAT_0049f2c0 - (int)DAT_0049f2bc;
    _DAT_0049f2c0 = &PTR_LAB_00480fb0;
    FUN_00454d40((undefined4 *)&DAT_0049f2c0);
    DAT_0049f34c[0xf] = (int)&DAT_0049f350 - (int)DAT_0049f34c;
    _DAT_0049f348 = &PTR_LAB_00480f98;
    *DAT_0049f34c = &PTR_LAB_00480fa4;
    DAT_0049f34c[0xf] = (int)&DAT_0049f350 - (int)DAT_0049f34c;
    _DAT_0049f350 = &PTR_LAB_00480fb0;
    FUN_00454d40((undefined4 *)&DAT_0049f350);
    DAT_0049f304[0xf] = (int)&DAT_0049f308 - (int)DAT_0049f304;
    _DAT_0049f300 = &PTR_LAB_00480f98;
    *DAT_0049f304 = &PTR_LAB_00480fa4;
    DAT_0049f304[0xf] = (int)&DAT_0049f308 - (int)DAT_0049f304;
    _DAT_0049f308 = &PTR_LAB_00480fb0;
    FUN_00454d40((undefined4 *)&DAT_0049f308);
  }
  LeaveCriticalSection(lpCriticalSection);
  return param_1;
}


