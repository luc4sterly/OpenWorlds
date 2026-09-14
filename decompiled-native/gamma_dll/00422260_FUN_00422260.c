// 00422260 FUN_00422260 [Global]
// programa: gamma.dll

HBITMAP __cdecl FUN_00422260(LONG param_1,int param_2,undefined4 *param_3,void **param_4)

{
  HDC hdc;
  HBITMAP pHVar1;
  int iVar2;
  
  hdc = CreateCompatibleDC((HDC)0x0);
  if (param_3 == (undefined4 *)0x0) {
    iVar2 = 4;
  }
  else {
    iVar2 = 1;
  }
  pHVar1 = FUN_00422150(hdc,param_1,param_2,param_3,param_4,iVar2,0);
  DeleteDC(hdc);
  return pHVar1;
}


