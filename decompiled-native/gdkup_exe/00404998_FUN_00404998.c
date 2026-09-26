// 00404998 FUN_00404998 [Global]
// programa: gdkup.exe

undefined8 __fastcall FUN_00404998(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  ushort in_DS;
  undefined8 uVar3;
  
  do {
    uVar3 = (*(code *)PTR_FUN_00408b38)();
    iVar2 = (int)((ulonglong)uVar3 >> 0x20);
    iVar1 = (int)uVar3 + iVar2;
    *(undefined4 *)(iVar1 + 0x58) = *(undefined4 *)(&DAT_00408de8 + iVar2);
    *(undefined4 *)(iVar1 + 0x5c) = *(undefined4 *)(&DAT_00408dec + iVar2);
  } while (iVar2 != 0x60);
  return CONCAT44(param_2,(uint)in_DS);
}


