// 00415190 _Java_NET_worlds_scape_Camera_renderScene@28 [Global]
// program: gamma.dll

undefined4
_Java_NET_worlds_scape_Camera_renderScene_28
          (int *param_1,undefined4 param_2,HWND param_3,uint param_4,uint param_5,uint param_6)

{
  HWND pHVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  float fVar7;
  float fVar8;
  
                    /* 0x15190  198  _Java_NET_worlds_scape_Camera_renderScene@28 */
  (**(code **)(*param_1 + 0x1b4))(param_1,param_2,DAT_00489478,param_6);
  pHVar1 = (HWND)FUN_0040c120();
  if (param_3 == pHVar1) {
    DAT_0049fcbc = param_4;
    DAT_0049ff64 = param_5;
  }
  uVar6 = 0;
  iVar2 = FUN_00412cf0(param_1,param_2);
  if (iVar2 != 0) {
    iVar3 = FUN_00419510(iVar2);
    if (iVar3 != 0) {
      if ((0 < (int)param_4) && (0 < (int)param_5)) {
        uVar6 = FUN_00415fb0(&DAT_004a0438,param_3,param_4,param_5);
        if (uVar6 == 0) {
          return 0;
        }
        DAT_0048948c = uVar6;
        uVar4 = FUN_00419950();
        FUN_004193c0(iVar2,uVar4);
        uVar5 = (**(code **)(*param_1 + 0x17c))(param_1,param_2,DAT_00489484);
        uVar5 = FUN_00425380(param_1,uVar5);
        FUN_00418c80(uVar4,uVar5);
        FUN_00418a90(uVar4,DAT_0046fd70,DAT_0046fd2c,DAT_0046fd6c,DAT_0046fd6c);
        FUN_00418b90(uVar6,uVar4);
        FUN_004198f0();
        FUN_00419cb0(uVar6,0,0,param_4,param_5);
        if ((int)param_5 < (int)param_4) {
          fVar7 = DAT_0046fd6c;
          fVar8 = (float)(int)param_5 / (float)(int)param_4;
        }
        else {
          fVar7 = (float)(int)param_4 / (float)(int)param_5;
          fVar8 = DAT_0046fd6c;
        }
        FUN_00419d00(uVar6,fVar7,fVar8);
        FUN_00419c80(uVar6,DAT_0046fd2c,DAT_0046fd2c);
      }
      FUN_00414aa0(param_1,iVar3,param_2,uVar6);
      if ((uVar6 != 0) && ((param_6 & 2) != 0)) {
        FUN_0041a020(uVar6);
      }
      iVar2 = (**(code **)(*param_1 + 0x3c))(param_1);
      if (iVar2 != 0) {
        return 0;
      }
      uVar4 = (**(code **)(*param_1 + 0x17c))(param_1,param_2,DAT_00489488);
      (**(code **)(*param_1 + 0x1a0))(param_1,param_2,DAT_00489488,0);
      return uVar4;
    }
  }
  return 0;
}


