// 00444740 FUN_00444740 [Global]
// programa: gamma.dll

undefined4 FUN_00444740(int param_1,int *param_2)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  undefined4 local_14;
  
  if (param_2 != (int *)0x0) {
    local_14 = 0;
    iVar1 = (**(code **)(**(int **)(param_1 + 8) + 0xc4))();
    if (*(int *)(param_1 + 0xc) == iVar1) {
      puVar2 = FUN_0044e010(0x14);
      if (puVar2 != (uint *)0x0) {
        uVar3 = *(uint *)(param_1 + 8);
        *puVar2 = (uint)&DAT_00477514;
        *puVar2 = (uint)&DAT_00479e64;
        *puVar2 = (uint)&PTR_LAB_00479e3c;
        puVar2[1] = 0;
        puVar2[2] = uVar3;
        puVar2[4] = 1;
        (**(code **)(*(int *)puVar2[2] + 0x80))((int *)puVar2[2]);
        if (param_1 == 0) {
          uVar3 = (**(code **)(*(int *)puVar2[2] + 0xc4))();
        }
        else {
          puVar2[1] = *(uint *)(param_1 + 4);
          uVar3 = *(uint *)(param_1 + 0xc);
        }
        puVar2[3] = uVar3;
      }
      *param_2 = (int)puVar2;
      if (*param_2 == 0) {
        local_14 = 0x8007000e;
      }
    }
    else {
      *param_2 = 0;
      local_14 = 0x80040203;
    }
    return local_14;
  }
  return 0x80004003;
}


