// 00401170 FUN_00401170 [Global]
// programa: run.exe

bool __cdecl FUN_00401170(LPCSTR param_1)

{
  FILE *pFVar1;
  
  pFVar1 = (FILE *)FUN_00401300(param_1,&DAT_004091a0);
  if (pFVar1 != (FILE *)0x0) {
    FUN_0040128a(pFVar1);
  }
  return pFVar1 != (FILE *)0x0;
}


