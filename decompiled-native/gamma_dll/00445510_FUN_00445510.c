// 00445510 FUN_00445510 [Global]
// programa: gamma.dll

undefined4 FUN_00445510(uint param_1,int *param_2)

{
  uint *puVar1;
  uint uVar2;
  
  if (param_2 == (int *)0x0) {
    return 0x80004003;
  }
  puVar1 = FUN_0044e010(0x14);
  if (puVar1 != (uint *)0x0) {
    *puVar1 = (uint)&DAT_00477514;
    *puVar1 = (uint)&DAT_00479e64;
    *puVar1 = (uint)&PTR_LAB_00479e3c;
    puVar1[1] = 0;
    puVar1[2] = param_1;
    puVar1[4] = 1;
    (**(code **)(*(int *)puVar1[2] + 0x80))((int *)puVar1[2]);
    uVar2 = (**(code **)(*(int *)puVar1[2] + 0xc4))();
    puVar1[3] = uVar2;
  }
  *param_2 = (int)puVar1;
  if (*param_2 == 0) {
    return 0x8007000e;
  }
  return 0;
}


