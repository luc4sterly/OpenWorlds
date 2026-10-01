// 00441950 FUN_00441950 [Global]
// program: gamma.dll

undefined4 FUN_00441950(int param_1,ushort *param_2,int *param_3)

{
  int iVar1;
  
  if (param_3 == (int *)0x0) {
    return 0x80004003;
  }
  iVar1 = FUN_0044b300(param_2,(ushort *)&DAT_0047b028);
  if (iVar1 == 0) {
    iVar1 = (**(code **)(*(int *)(param_1 + -0xc) + 0xb8))(0);
    if (iVar1 != 0) {
      iVar1 = iVar1 + 0xc;
    }
    *param_3 = iVar1;
    (**(code **)(*(int *)*param_3 + 4))((int *)*param_3);
    return 0;
  }
  *param_3 = 0;
  return 0x80040216;
}


