// 0042fd49 FUN_0042fd49 [Global]
// programa: sfmain.exe

int __fastcall FUN_0042fd49(undefined4 param_1,uint param_2)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  int local_20;
  int local_1c;
  
  if (*(int *)(in_EAX + 0x20) == 0) {
    lVar5 = FUN_0042fd0e(0,param_2);
    if ((int)lVar5 == 0) {
      iVar3 = *(int *)(&DAT_00437ce4 + *(int *)(in_EAX + 0x10) * 2);
      iVar1 = *(int *)(&DAT_00437ce2 + *(int *)(in_EAX + 0x10) * 2);
    }
    else {
      iVar3 = *(int *)(&DAT_00437cfe + *(int *)(in_EAX + 0x10) * 2);
      iVar1 = *(int *)(&DAT_00437cfc + *(int *)(in_EAX + 0x10) * 2);
    }
    FUN_0042f500(1,(int)((ulonglong)lVar5 >> 0x20));
    iVar4 = ((*(int *)(in_EAX + 0x18) - local_20) + 7) % 7;
    if (*(int *)(in_EAX + 0xc) == 5) {
      iVar2 = 4;
      if ((iVar3 >> 0x10) - (iVar1 >> 0x10) < iVar4 + 0x1d) {
        iVar2 = *(int *)(in_EAX + 0xc) + -2;
      }
    }
    else {
      iVar2 = *(int *)(in_EAX + 0xc) + -1;
    }
    iVar3 = iVar2 * 7 + local_1c + iVar4;
  }
  else if (*(int *)(in_EAX + 0x20) == 1) {
    iVar3 = *(int *)(in_EAX + 0x1c) + -1;
  }
  else {
    iVar3 = *(int *)(in_EAX + 0x1c);
  }
  return iVar3;
}


