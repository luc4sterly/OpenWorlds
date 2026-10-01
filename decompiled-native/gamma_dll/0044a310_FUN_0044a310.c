// 0044a310 FUN_0044a310 [Global]
// program: gamma.dll

void __fastcall FUN_0044a310(int *param_1)

{
  DWORD DVar1;
  
  (**(code **)(*param_1 + 0x1a8))(param_1[0x4a],param_1[0x4b]);
  DVar1 = timeGetTime();
  param_1[0x36] = DVar1;
  return;
}


