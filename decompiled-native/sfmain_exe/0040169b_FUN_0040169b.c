// 0040169b FUN_0040169b [Global]
// programa: sfmain.exe

void __fastcall FUN_0040169b(undefined4 param_1,float *param_2)

{
  undefined4 *in_EAX;
  int iVar1;
  float *pfVar3;
  undefined4 *puVar4;
  float afStack_54 [6];
  float local_3c [5];
  float local_28 [5];
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = iVar2 + 4;
    *(undefined4 *)((int)afStack_54 + iVar2 + 0x2c) = 0;
    *(undefined4 *)((int)afStack_54 + iVar2 + 4) = *(undefined4 *)((int)afStack_54 + iVar2 + 0x2c);
    *(undefined4 *)((int)afStack_54 + iVar2 + 0x18) = *(undefined4 *)((int)afStack_54 + iVar2 + 4);
    iVar2 = iVar1;
  } while (iVar1 != 0x14);
  puVar4 = in_EAX + 0x30;
  do {
    local_3c[0] = (float)*in_EAX;
    afStack_54[1] = (float)*in_EAX;
    iVar2 = 1;
    pfVar3 = param_2;
    do {
      pfVar3 = pfVar3 + 1;
      afStack_54[iVar2 + 1] = *pfVar3 * afStack_54[iVar2 + 10] + afStack_54[iVar2];
      iVar1 = iVar2 + 1;
      afStack_54[iVar2 + 6] = *pfVar3 * afStack_54[iVar2] + afStack_54[iVar2 + 10];
      afStack_54[iVar2 + 10] = afStack_54[iVar2 + 5];
      iVar2 = iVar1;
    } while (iVar1 < 5);
    *in_EAX = afStack_54[5];
    in_EAX = in_EAX + 1;
  } while (in_EAX != puVar4);
  return;
}


