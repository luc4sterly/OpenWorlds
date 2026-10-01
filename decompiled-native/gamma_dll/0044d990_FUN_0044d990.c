// 0044d990 FUN_0044d990 [Global]
// program: gamma.dll

uint * __cdecl FUN_0044d990(uint *param_1,uint param_2)

{
  DWORD nBufferLength;
  LPVOID pvVar1;
  
  nBufferLength = GetCurrentDirectoryA(0,(LPSTR)0x0);
  if (param_1 == (uint *)0x0) {
    if ((int)nBufferLength < (int)param_2) {
      nBufferLength = param_2;
    }
    param_1 = FUN_00454a10(nBufferLength);
    if (param_1 == (uint *)0x0) {
      pvVar1 = FUN_00453ed0();
      *(undefined4 *)((int)pvVar1 + 4) = 0xb;
      return (uint *)0x0;
    }
  }
  else if ((int)param_2 < (int)nBufferLength) {
    pvVar1 = FUN_00453ed0();
    *(undefined4 *)((int)pvVar1 + 4) = 0x22;
    return (uint *)0x0;
  }
  GetCurrentDirectoryA(nBufferLength,(LPSTR)param_1);
  return param_1;
}


