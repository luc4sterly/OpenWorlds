// 0042c7fc FUN_0042c7fc [Global]
// programa: sfmain.exe

undefined8 __fastcall FUN_0042c7fc(undefined4 param_1,undefined4 param_2)

{
  undefined4 in_EAX;
  undefined4 extraout_ECX;
  undefined4 *puVar1;
  undefined8 uVar2;
  
  uVar2 = FUN_0042f49b(param_1,in_EAX);
  uVar2 = FUN_0042f500(extraout_ECX,(int)((ulonglong)uVar2 >> 0x20));
  puVar1 = (undefined4 *)((ulonglong)uVar2 >> 0x20);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = (int)uVar2;
  }
  return CONCAT44(param_2,(int)uVar2);
}


