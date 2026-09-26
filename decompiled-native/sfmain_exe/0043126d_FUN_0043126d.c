// 0043126d FUN_0043126d [Global]
// programa: sfmain.exe

undefined8 __fastcall FUN_0043126d(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  ushort in_DS;
  undefined8 uVar3;
  
  do {
    uVar3 = (*(code *)PTR_FUN_0043e7ec)();
    iVar2 = (int)((ulonglong)uVar3 >> 0x20);
    iVar1 = (int)uVar3 + iVar2;
    *(undefined4 *)(iVar1 + 0x58) = *(undefined4 *)(&DAT_0043e9d4 + iVar2);
    *(undefined4 *)(iVar1 + 0x5c) = *(undefined4 *)(&DAT_0043e9d8 + iVar2);
  } while (iVar2 != 0x60);
  return CONCAT44(param_2,(uint)in_DS);
}


