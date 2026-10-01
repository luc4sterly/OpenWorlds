// 10018b20 RwGetNumNamedTextures [Global]
// program: RWL21.DLL

int RwGetNumNamedTextures(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
                    /* 0x18b20  211  RwGetNumNamedTextures */
  if (DAT_1005abfc == 0) {
    return 0;
  }
  iVar4 = 1;
  if (DAT_1005ac00 != 1) {
    iVar4 = DAT_1005abfc;
  }
  iVar2 = 0;
  if (0 < iVar4) {
    piVar3 = (int *)(DAT_1005abf4 + (DAT_1005abfc + -1) * 4);
    do {
      iVar1 = *piVar3;
      piVar3 = piVar3 + -1;
      iVar2 = iVar2 + *(int *)(iVar1 + 8);
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  return iVar2;
}


