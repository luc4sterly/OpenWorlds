// 004078ca FUN_004078ca [Global]
// program: sfmain.exe

undefined8 __fastcall FUN_004078ca(undefined4 param_1,undefined4 param_2)

{
  int extraout_ECX;
  int iVar1;
  undefined8 uVar2;
  
  uVar2 = FUN_0042ba46(param_1,param_2);
  iVar1 = 0;
  if ((int)uVar2 != 0) {
    FUN_00408098((int)uVar2,0);
    *(undefined2 *)(extraout_ECX + 0x26e) = 0x28;
    iVar1 = extraout_ECX;
  }
  return CONCAT44(param_2,iVar1);
}


