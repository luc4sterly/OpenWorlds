// 004182d0 FUN_004182d0 [Global]
// programa: gamma.dll

int __cdecl FUN_004182d0(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  iVar2 = 0;
  iVar1 = 0;
  if ((param_2 != (undefined4 *)0x0) && (param_3 == DAT_00489570)) {
    iVar1 = RwCreateUserRaster(0x80,0x80,DAT_0048956c,param_2);
    if (iVar1 != 0) {
      iVar2 = RwCreateTexture(iVar1);
      if (iVar2 != 0) {
        RwSetRasterData(iVar1,param_2);
        RwSetTextureData(iVar2,1);
        if (param_1 != 0) {
          RwAddTextureToDict(param_1,iVar2);
        }
      }
    }
  }
  if (iVar2 == 0) {
    if (iVar1 != 0) {
      RwDestroyRaster(iVar1);
    }
    FUN_00454a60(param_2);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return iVar2;
}


