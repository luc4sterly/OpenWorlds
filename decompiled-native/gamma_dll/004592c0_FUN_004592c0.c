// 004592c0 FUN_004592c0 [Global]
// program: gamma.dll

bool __cdecl FUN_004592c0(LPCSTR param_1)

{
  BOOL BVar1;
  
  BVar1 = DeleteFileA(param_1);
  return BVar1 == 0;
}


