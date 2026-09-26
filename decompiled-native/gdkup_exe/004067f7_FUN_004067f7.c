// 004067f7 FUN_004067f7 [Global]
// programa: gdkup.exe

undefined8 __fastcall FUN_004067f7(undefined4 param_1,uint param_2)

{
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar1;
  LPVOID pvVar2;
  longlong lVar3;
  
  lVar3 = FUN_004051d8(param_1,param_2);
  pvVar2 = (LPVOID)0x0;
  uVar1 = extraout_ECX;
  if ((int)lVar3 != 0) {
    pvVar2 = TlsGetValue(DAT_00408b34);
    uVar1 = extraout_ECX_00;
  }
  if (pvVar2 == (LPVOID)0x0) {
    FUN_00404195(uVar1,1);
  }
  return CONCAT44(param_2,pvVar2);
}


