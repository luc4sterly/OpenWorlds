// 00418540 FUN_00418540 [Global]
// program: gamma.dll

void __cdecl FUN_00418540(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int local_18;
  int local_14;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  if ((((DAT_00489578 != 0) && (param_1 != 0)) && (param_2 != 0)) && (param_3 != 0)) {
    iVar1 = RwGetTextureRaster(param_1);
    if (iVar1 != 0) {
      puVar2 = (undefined4 *)RwGetRasterData(iVar1);
      if (puVar2 != (undefined4 *)0x0) {
        local_18 = param_2;
        local_14 = param_3;
        iVar1 = RwBitmapRaster(&local_18,0);
        if (iVar1 != 0) {
          RwSetTextureRaster(param_1,iVar1);
          FUN_00454a60(puVar2);
        }
      }
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return;
}


