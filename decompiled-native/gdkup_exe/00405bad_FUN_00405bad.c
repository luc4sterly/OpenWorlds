// 00405bad FUN_00405bad [Global]
// programa: gdkup.exe

undefined8 __fastcall FUN_00405bad(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  ushort *puVar2;
  int in_EAX;
  int *piVar3;
  undefined4 uVar4;
  int extraout_ECX;
  int extraout_ECX_00;
  int extraout_ECX_01;
  int iVar5;
  int iVar6;
  
  iVar6 = *(int *)(in_EAX + 4);
  do {
    while( true ) {
      piVar3 = (int *)FUN_00405ad4(in_EAX,iVar6);
      iVar5 = extraout_ECX;
      if (((piVar3 == (int *)0x0) || (*(int *)(extraout_ECX + 4) == *(int *)(extraout_ECX + 9))) ||
         (*piVar3 != 0)) goto LAB_00405c34;
      puVar2 = (ushort *)piVar3[1];
      uVar1 = *puVar2;
      if (1 < uVar1) break;
      if (uVar1 != 1) {
LAB_00405c25:
        FUN_00405c57();
        iVar5 = extraout_ECX_01;
LAB_00405c34:
        *(int *)(iVar5 + 4) = iVar6;
        return CONCAT44(param_2,piVar3);
      }
      iVar6 = *(int *)(puVar2 + 1);
      in_EAX = extraout_ECX;
    }
    if (uVar1 < 5) goto LAB_00405c34;
    if (5 < uVar1) {
      if (0xb < uVar1) goto LAB_00405c25;
      goto LAB_00405c34;
    }
    uVar4 = FUN_00406b04(extraout_ECX,*(uint *)(puVar2 + 1));
    in_EAX = extraout_ECX_00;
    if ((char)uVar4 == '\0') {
      iVar6 = *(int *)(puVar2 + 5);
    }
    else {
      iVar6 = *(int *)(puVar2 + 3);
    }
  } while( true );
}


