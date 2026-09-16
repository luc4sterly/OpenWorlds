// 00448980 FUN_00448980 [Global]
// programa: gamma.dll

undefined4 __fastcall FUN_00448980(int *param_1)

{
  DWORD DVar1;
  HANDLE pvStack_18;
  int iStack_14;
  
  pvStack_18 = (HANDLE)param_1[0x14];
  iStack_14 = param_1[0x13];
  (**(code **)(*param_1 + 0xec))();
  do {
    DVar1 = WaitForMultipleObjects(2,&pvStack_18,0,10000);
  } while (DVar1 == 0x102);
  (**(code **)(*param_1 + 0xf0))();
  if (DVar1 == 0) {
    return 0x80040223;
  }
  FUN_00449290((int)param_1);
  return 0;
}


