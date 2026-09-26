// 00403d78 FUN_00403d78 [Global]
// programa: gdkup.exe

undefined8 __fastcall FUN_00403d78(undefined4 param_1,undefined4 param_2)

{
  byte *pbVar1;
  undefined4 in_EAX;
  undefined4 *puVar2;
  undefined8 uVar3;
  
  uVar3 = FUN_00403da7(param_1,in_EAX);
  puVar2 = (undefined4 *)((ulonglong)uVar3 >> 0x20);
  if ((int)uVar3 == 0) {
    return CONCAT44(param_2,0xffffffff);
  }
  pbVar1 = (byte *)*puVar2;
  puVar2[1] = puVar2[1] + -1;
  *puVar2 = pbVar1 + 1;
  return CONCAT44(param_2,(uint)*pbVar1);
}


