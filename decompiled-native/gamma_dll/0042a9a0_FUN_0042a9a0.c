// 0042a9a0 FUN_0042a9a0 [Global]
// programa: gamma.dll

void __thiscall FUN_0042a9a0(int *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  if (param_2 != 0) {
    (**(code **)(*param_1 + 0xc))(param_1[10]);
    uVar1 = (**(code **)(*param_1 + 8))(param_2,0x4000);
    (**(code **)(*param_1 + 4))(uVar1);
  }
  if (param_3 != 0) {
    param_1[9] = param_3;
  }
  return;
}


