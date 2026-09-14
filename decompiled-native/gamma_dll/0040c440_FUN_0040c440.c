// 0040c440 FUN_0040c440 [Global]
// programa: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong __fastcall
FUN_0040c440(undefined4 *param_1,uint param_2,int param_3,uint param_4,int param_5)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  longlong lVar8;
  uint local_14;
  
  if ((param_3 == 0x105) || (param_3 == 0x101)) {
    local_14 = 0;
  }
  else {
    if ((param_5 >> 0x10 & 0x4000U) != 0) {
      return (ulonglong)param_2 << 0x20;
    }
    if (param_3 == 0x102) {
      FUN_0040c2c0(param_1,3,param_4);
      return CONCAT44(extraout_EDX,1);
    }
    if ((param_3 != 0x104) && (param_3 != 0x100)) {
      return (ulonglong)param_2 << 0x20;
    }
    local_14 = 1;
  }
  if ((((param_3 - 0x104U < 2) && (param_4 != 0x25)) && (param_4 != 0x27)) &&
     ((param_4 != 0x26 && (param_4 != 0x28)))) {
    return (ulonglong)param_2 << 0x20;
  }
  if (param_4 < 0x100) {
    uVar6 = param_4;
    if (((param_4 < 0x30) || (0x39 < param_4)) && ((param_4 < 0x41 || (0x5a < param_4)))) {
      if (param_4 == 0x20) {
                    /* WARNING: Could not recover jumptable at 0x0040c539. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        lVar8 = (*(code *)PTR_DAT_0046ef20)();
        return lVar8;
      }
      param_2 = param_4;
      uVar6 = param_4 | 0xe300;
    }
  }
  else {
    uVar6 = 0;
  }
  if (uVar6 != 0) {
    bVar1 = false;
    bVar2 = false;
    if ((param_4 < 5) && (param_4 != 0)) {
      bVar1 = true;
    }
    if ((bVar1) && (param_4 != 3)) {
      bVar2 = true;
    }
    if (bVar2) {
      SendMessageA((HWND)*param_1,0x8065,local_14 | _DAT_0046e8a0,0);
    }
    uVar7 = param_4 >> 5;
    uVar5 = 1 << ((byte)param_4 & 0x1f);
    if ((uVar5 & *(uint *)(&DAT_0048927c + uVar7 * 4)) != 0) {
      if (bVar2) {
        iVar3 = 5;
      }
      else {
        iVar3 = 2;
      }
      FUN_0040c2c0(param_1,iVar3,uVar6);
      *(uint *)(&DAT_0048927c + uVar7 * 4) = *(uint *)(&DAT_0048927c + uVar7 * 4) & ~uVar5;
    }
    if (local_14 == 0) {
      if (bVar2) {
        iVar3 = 5;
      }
      else {
        iVar3 = 2;
      }
      FUN_0040c2c0(param_1,iVar3,uVar6);
      uVar4 = extraout_EDX_01;
    }
    else {
      if (bVar2) {
        iVar3 = 4;
      }
      else {
        iVar3 = 1;
      }
      FUN_0040c2c0(param_1,iVar3,uVar6);
      *(uint *)(&DAT_0048927c + uVar7 * 4) = *(uint *)(&DAT_0048927c + uVar7 * 4) | uVar5;
      uVar4 = extraout_EDX_00;
    }
    return CONCAT44(uVar4,1);
  }
  return (ulonglong)param_2 << 0x20;
}


