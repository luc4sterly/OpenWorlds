// 1001d5c0 FUN_1001d5c0 [Global]
// programa: RWL21.DLL

undefined4 __fastcall FUN_1001d5c0(undefined4 param_1,int param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 *puVar6;
  undefined8 uVar7;
  
  iVar1 = param_3[1];
  iVar2 = param_3[2];
  param_3[2] = iVar2 + 1;
  if (iVar1 <= iVar2 + 1) {
    iVar1 = (iVar1 >> 1) + iVar1;
    param_2 = (**(code **)(PTR_DAT_1005b69c + 0x354))(*param_3,iVar1 * 4);
    if (param_2 == 0) {
      param_3[2] = param_3[2] + -1;
      FUN_1000cba0(3);
      return 0;
    }
    iVar2 = param_3[1];
    if (iVar2 < iVar1) {
      puVar6 = (undefined4 *)(param_2 + iVar2 * 4);
      for (iVar5 = iVar1 - iVar2; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar6 = 0;
        puVar6 = puVar6 + 1;
      }
    }
    *param_3 = param_2;
    param_3[1] = iVar1;
  }
  puVar6 = (undefined4 *)(*param_3 + param_3[2] * 4);
  if ((undefined4 *)*puVar6 == (undefined4 *)0x0) {
    puVar6 = (undefined4 *)puVar6[-1];
    if (puVar6 == (undefined4 *)0x0) {
      FUN_1000cba0(1);
      uVar4 = 0;
    }
    else {
      puVar3 = FUN_10037030(DAT_1005ac38);
      if (puVar3 == (undefined4 *)0x0) {
        FUN_1000cba0(3);
        uVar4 = 0;
      }
      else {
        *(undefined1 *)(puVar3 + 0x10) = 0;
        *(undefined1 *)((int)puVar3 + 0x41) = 1;
        puVar3[0xf] = 0x3f800000;
        puVar3[10] = 0x3f800000;
        puVar3[5] = 0x3f800000;
        *puVar3 = 0x3f800000;
        puVar3[0xe] = 0;
        puVar3[0xd] = 0;
        puVar3[0xc] = 0;
        puVar3[0xb] = 0;
        puVar3[9] = 0;
        puVar3[8] = 0;
        puVar3[7] = 0;
        puVar3[6] = 0;
        puVar3[4] = 0;
        puVar3[3] = 0;
        puVar3[2] = 0;
        puVar3[1] = 0;
        *(undefined1 *)((int)puVar3 + 0x41) = 1;
        *(undefined1 *)(puVar3 + 0x10) = 1;
        uVar7 = FUN_100510e0(extraout_ECX,extraout_EDX,puVar6,puVar3);
        uVar4 = (undefined4)uVar7;
      }
    }
    *(undefined4 *)(*param_3 + param_3[2] * 4) = uVar4;
    if (*(int *)(*param_3 + param_3[2] * 4) == 0) {
      param_3[2] = param_3[2] + -1;
      return 0;
    }
  }
  else {
    FUN_100510e0(puVar6,param_2,(undefined4 *)puVar6[-1],(undefined4 *)*puVar6);
  }
  return *(undefined4 *)(*param_3 + param_3[2] * 4);
}


