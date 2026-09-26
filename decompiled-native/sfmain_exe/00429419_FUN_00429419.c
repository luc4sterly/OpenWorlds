// 00429419 FUN_00429419 [Global]
// programa: sfmain.exe

void __cdecl FUN_00429419(HDC param_1,int param_2,int param_3,LPCSTR param_4)

{
  CHAR local_420 [1024];
  int local_20;
  va_list local_1c;
  
  local_1c = &stack0x00000014;
  local_20 = wvsprintfA(local_420,param_4,local_1c);
  local_1c = (va_list)0x0;
  TextOutA(param_1,param_3 * DAT_004627b4,param_2 * DAT_004627c4,local_420,local_20);
  return;
}


