// 00405b28 FUN_00405b28 [Global]
// program: gdkup.exe

undefined8 __fastcall FUN_00405b28(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  ushort *puVar2;
  int *in_EAX;
  undefined4 uVar3;
  int iVar4;
  int extraout_ECX;
  int *local_1c;
  
  if (*in_EAX == 0) {
    local_1c = (int *)0x0;
  }
  else {
    iVar4 = in_EAX[1];
    if (iVar4 != 0) {
      iVar4 = iVar4 + -1;
    }
    while (iVar4 != 0) {
      if ((iVar4 == *(int *)((int)in_EAX + 9)) ||
         (local_1c = (int *)FUN_00405ad4(iVar4,iVar4), iVar4 = extraout_ECX, *local_1c != 0))
      goto LAB_00405b80;
      puVar2 = (ushort *)local_1c[1];
      uVar1 = *puVar2;
      if (uVar1 == 0) goto LAB_00405b80;
      if (uVar1 < 2) {
        iVar4 = *(int *)(puVar2 + 1);
      }
      else {
        if (uVar1 != 5) goto LAB_00405b80;
        uVar3 = FUN_00406b04(extraout_ECX,*(uint *)(puVar2 + 1));
        if ((char)uVar3 == '\0') {
          iVar4 = *(int *)(puVar2 + 5);
        }
        else {
          iVar4 = *(int *)(puVar2 + 3);
        }
      }
    }
    local_1c = (int *)0x0;
LAB_00405b80:
    in_EAX[1] = iVar4;
  }
  return CONCAT44(param_2,local_1c);
}


