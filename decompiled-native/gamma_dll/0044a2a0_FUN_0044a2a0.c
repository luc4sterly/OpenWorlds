// 0044a2a0 FUN_0044a2a0 [Global]
// programa: gamma.dll

void __fastcall FUN_0044a2a0(int *param_1)

{
  DWORD dwMilliseconds;
  
  param_1[0x34] = 0;
  param_1[0x35] = 5000000;
  (**(code **)(*param_1 + 0x1a8))(param_1[0x4a],param_1[0x4b]);
  if (param_1[0x33] < 1) {
    dwMilliseconds = 0;
  }
  else {
    dwMilliseconds = param_1[0x33] / 10000;
  }
  Sleep(dwMilliseconds);
  return;
}


