// 00432008 FUN_00432008 [Global]
// programa: sfmain.exe

void __fastcall FUN_00432008(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int in_EAX;
  int iVar3;
  undefined8 uVar4;
  
  iVar1 = *(int *)(in_EAX + 4);
  uVar4 = FUN_00431faa(param_1,*(undefined4 *)(in_EAX + 8));
  iVar3 = (int)((ulonglong)uVar4 >> 0x20);
  if ((int)uVar4 == 0) {
    iVar2 = iVar3;
    if (iVar1 != 0) {
      *(int *)(iVar1 + 8) = iVar3;
      iVar2 = DAT_0043e524;
    }
    DAT_0043e524 = iVar2;
    if (iVar3 != 0) {
      *(int *)(iVar3 + 4) = iVar1;
    }
  }
  return;
}


