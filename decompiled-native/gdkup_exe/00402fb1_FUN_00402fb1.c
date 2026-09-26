// 00402fb1 FUN_00402fb1 [Global]
// programa: gdkup.exe

undefined8 __fastcall FUN_00402fb1(undefined4 param_1,undefined4 param_2)

{
  int in_EAX;
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 extraout_ECX;
  
  (*(code *)PTR_FUN_00408b4c)();
  puVar1 = DAT_0040b464;
  while( true ) {
    if (puVar1 == (undefined4 *)0x0) {
      (*(code *)PTR_FUN_00408b50)();
      return CONCAT44(param_2,0xffffffff);
    }
    if (in_EAX == puVar1[1]) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  (*(code *)PTR_FUN_00408b50)();
  uVar2 = FUN_00402ff0(extraout_ECX,1);
  return CONCAT44(param_2,uVar2);
}


