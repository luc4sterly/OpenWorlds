// 00444820 FUN_00444820 [Global]
// program: gamma.dll

uint FUN_00444820(int param_1,uint param_2,int *param_3,int *param_4)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  LPVOID pvVar4;
  int iStack_5c;
  undefined4 uStack_58;
  undefined2 uStack_54;
  undefined2 uStack_52;
  undefined2 uStack_50;
  undefined2 uStack_4e;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined2 uStack_44;
  undefined2 uStack_42;
  undefined2 uStack_40;
  undefined2 uStack_3e;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined2 uStack_28;
  undefined2 uStack_26;
  undefined2 uStack_24;
  undefined2 uStack_22;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  if (param_3 == (int *)0x0) {
    return 0x80004003;
  }
  iVar3 = (**(code **)(**(int **)(param_1 + 8) + 0xc4))();
  if (*(int *)(param_1 + 0xc) != iVar3) {
    return 0x80040203;
  }
  if (param_4 == (int *)0x0) {
    if (1 < param_2) {
      return 0x80070057;
    }
  }
  else {
    *param_4 = 0;
  }
  iStack_5c = 0;
  do {
    if (param_2 == 0) {
LAB_004449a6:
      if (param_4 != (int *)0x0) {
        *param_4 = iStack_5c;
      }
      return (uint)(param_2 != 0);
    }
    FUN_00448100(&uStack_58);
    uVar1 = *(undefined4 *)(param_1 + 4);
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
    iVar3 = (**(code **)(**(int **)(param_1 + 8) + 0xe8))(uVar1,&uStack_58);
    if (iVar3 != 0) {
      FUN_004480e0((int)&uStack_58);
      goto LAB_004449a6;
    }
    pvVar4 = CoTaskMemAlloc(0x48);
    *param_3 = (int)pvVar4;
    puVar2 = (undefined4 *)*param_3;
    if (puVar2 == (undefined4 *)0x0) {
      FUN_004480e0((int)&uStack_58);
      goto LAB_004449a6;
    }
    param_3 = param_3 + 1;
    *puVar2 = uStack_58;
    *(undefined2 *)(puVar2 + 1) = uStack_54;
    *(undefined2 *)((int)puVar2 + 6) = uStack_52;
    puVar2[2] = CONCAT22(uStack_4e,uStack_50);
    puVar2[3] = uStack_4c;
    puVar2[4] = uStack_48;
    *(undefined2 *)(puVar2 + 5) = uStack_44;
    *(undefined2 *)((int)puVar2 + 0x16) = uStack_42;
    puVar2[6] = CONCAT22(uStack_3e,uStack_40);
    puVar2[7] = uStack_3c;
    puVar2[8] = uStack_38;
    puVar2[9] = uStack_34;
    puVar2[10] = uStack_30;
    puVar2[0xb] = uStack_2c;
    *(undefined2 *)(puVar2 + 0xc) = uStack_28;
    *(undefined2 *)((int)puVar2 + 0x32) = uStack_26;
    puVar2[0xd] = CONCAT22(uStack_22,uStack_24);
    puVar2[0xe] = uStack_20;
    puVar2[0xf] = uStack_1c;
    puVar2[0x10] = uStack_18;
    puVar2[0x11] = uStack_14;
    param_2 = param_2 - 1;
    uStack_14 = 0;
    iStack_5c = iStack_5c + 1;
    uStack_18 = 0;
    uStack_1c = 0;
    FUN_004480e0((int)&uStack_58);
  } while( true );
}


