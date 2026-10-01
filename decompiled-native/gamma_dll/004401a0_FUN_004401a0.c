// 004401a0 FUN_004401a0 [Global]
// program: gamma.dll

int __fastcall FUN_004401a0(int *param_1)

{
  DWORD DVar1;
  HANDLE pvStack_c;
  
  pvStack_c = (HANDLE)param_1[4];
  if (pvStack_c != (HANDLE)0x0) {
    DVar1 = MsgWaitForMultipleObjects(1,&pvStack_c,0,0,0xff);
    if ((DVar1 != 1) && (DVar1 == 0)) {
      FUN_004401f0(param_1);
    }
  }
  return param_1[2];
}


