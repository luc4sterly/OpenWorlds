// 0042c83b FUN_0042c83b [Global]
// programa: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __fastcall FUN_0042c83b(undefined4 param_1,undefined4 param_2)

{
  int in_EAX;
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 extraout_ECX;
  
  (*(code *)PTR_FUN_0043e800)();
  puVar1 = _DAT_004e57b8;
  while( true ) {
    if (puVar1 == (undefined4 *)0x0) {
      (*(code *)PTR_FUN_0043e804)();
      return CONCAT44(param_2,0xffffffff);
    }
    if (in_EAX == puVar1[1]) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  (*(code *)PTR_FUN_0043e804)();
  uVar2 = FUN_0042c87a(extraout_ECX,1);
  return CONCAT44(param_2,uVar2);
}


