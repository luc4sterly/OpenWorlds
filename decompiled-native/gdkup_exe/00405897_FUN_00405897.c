// 00405897 FUN_00405897 [Global]
// program: gdkup.exe

undefined8 __fastcall FUN_00405897(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 extraout_ECX;
  int extraout_EDX;
  undefined8 uVar3;
  
  iVar1 = DAT_00408e8c;
  uVar3 = FUN_00406a2a(param_1,param_2);
  iVar2 = (int)uVar3;
  if ((iVar2 != -1) && (iVar1 == 0)) {
    FUN_00406aa0(extraout_ECX,iVar2);
    iVar2 = extraout_EDX;
  }
  return CONCAT44(param_2,iVar2);
}


