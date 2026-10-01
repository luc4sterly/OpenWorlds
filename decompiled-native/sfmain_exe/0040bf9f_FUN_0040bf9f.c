// 0040bf9f FUN_0040bf9f [Global]
// program: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0040bf9f(undefined4 param_1,int param_2)

{
  float fVar1;
  float *in_EAX;
  int iVar2;
  
  for (iVar2 = 1; in_EAX = in_EAX + 1, iVar2 <= param_2; iVar2 = iVar2 + 1) {
    fVar1 = *in_EAX;
    *in_EAX = (_DAT_00438c9c * (float)_DAT_00435a08 +
              ((DAT_00438c94 * (float)_DAT_004359f8 +
               (fVar1 - DAT_00438c8c * (float)_DAT_004359f0) + _DAT_00438c90) -
              DAT_00438c98 * (float)_DAT_00435a00)) - _DAT_00438ca0 * (float)_DAT_00435a10;
    _DAT_00438c90 = DAT_00438c8c;
    _DAT_00438ca0 = _DAT_00438c9c;
    _DAT_00438c9c = DAT_00438c98;
    DAT_00438c98 = DAT_00438c94;
    DAT_00438c94 = *in_EAX;
    DAT_00438c8c = fVar1;
  }
  return;
}


