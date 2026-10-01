// 10010440 FUN_10010440 [Global]
// program: RWL21.DLL

bool FUN_10010440(FILE *param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  float *pfVar4;
  char *pcVar5;
  bool bVar6;
  float *local_44;
  float local_3c;
  float local_38;
  float local_34;
  float local_30 [2];
  float local_28 [3];
  char local_1c [28];
  
  iVar2 = FUN_10020800(param_1,s__f_f_f_1005aab4);
  if (iVar2 != 3) {
    FUN_1000cba0(5);
    return false;
  }
  pfVar4 = (float *)0x0;
  local_44 = (float *)0x0;
  iVar2 = FUN_100206d0(param_1,local_1c,0x18);
  do {
    if ((iVar2 == 0) || (local_1c[0] == '#')) {
      iVar2 = RwVertexExt(local_34,local_38,local_3c,local_44,pfVar4);
      return 0 < iVar2;
    }
    pcVar3 = local_1c;
    cVar1 = local_1c[0];
    while (bVar6 = cVar1 == '\0', !bVar6) {
      cVar1 = *pcVar3;
      if (('@' < cVar1) && (cVar1 < '[')) {
        *pcVar3 = cVar1 + ' ';
      }
      pcVar5 = pcVar3 + 1;
      pcVar3 = pcVar3 + 1;
      cVar1 = *pcVar5;
    }
    iVar2 = 3;
    pcVar3 = local_1c;
    pcVar5 = &DAT_1005aab0;
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar6 = *pcVar3 == *pcVar5;
      pcVar3 = pcVar3 + 1;
      pcVar5 = pcVar5 + 1;
    } while (bVar6);
    if (bVar6) {
      iVar2 = FUN_10020800(param_1,&DAT_1005aaa8);
      if (iVar2 != 2) {
        FUN_1000cba0(5);
        return false;
      }
      local_44 = local_30;
    }
    else {
      iVar2 = 7;
      pcVar3 = local_1c;
      pcVar5 = s_normal_1005aaa0;
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar6 = *pcVar3 == *pcVar5;
        pcVar3 = pcVar3 + 1;
        pcVar5 = pcVar5 + 1;
      } while (bVar6);
      if (!bVar6) {
        FUN_1000cba0(4);
        return false;
      }
      iVar2 = FUN_10020800(param_1,s__f_f_f_1005aab4);
      if (iVar2 != 3) {
        FUN_1000cba0(5);
        return false;
      }
      pfVar4 = local_28;
    }
    iVar2 = FUN_100206d0(param_1,local_1c,0x18);
  } while( true );
}


