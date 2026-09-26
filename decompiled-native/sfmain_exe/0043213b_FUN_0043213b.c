// 0043213b FUN_0043213b [Global]
// programa: sfmain.exe

undefined8 __fastcall FUN_0043213b(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 extraout_ECX;
  int extraout_EDX;
  undefined8 uVar3;
  
  iVar1 = DAT_0043e85c;
  uVar3 = FUN_00432e11(param_1,param_2);
  iVar2 = (int)uVar3;
  if ((iVar2 != -1) && (iVar1 == 0)) {
    FUN_00432e87(extraout_ECX,iVar2);
    iVar2 = extraout_EDX;
  }
  return CONCAT44(param_2,iVar2);
}


