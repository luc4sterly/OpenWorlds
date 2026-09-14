// 0041cba0 _Java_NET_worlds_scape_ShapeLoader_loadTextFile@16 [Global]
// programa: gamma.dll

void _Java_NET_worlds_scape_ShapeLoader_loadTextFile_16
               (int *param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  LPCSTR pCVar4;
  byte *pbVar5;
  char *pcVar6;
  int *piVar7;
  int iVar8;
  byte *pbVar9;
  byte *pbVar10;
  byte *pbVar11;
  byte *pbVar12;
  undefined **local_5e0;
  undefined4 *local_5dc;
  undefined **local_5d4 [7];
  undefined4 local_5b8 [2];
  undefined *local_5b0;
  undefined **local_590 [16];
  byte local_550 [1024];
  char local_150 [260];
  int local_4c [2];
  undefined1 local_41;
  
                    /* 0x1cba0  288  _Java_NET_worlds_scape_ShapeLoader_loadTextFile@16 */
  pCVar4 = (LPCSTR)(**(code **)(*param_1 + 0x2a4))(param_1,param_3,0);
  FUN_00411980(&local_5e0,1,pCVar4,8);
  (**(code **)(*param_1 + 0x2a8))(param_1,param_3,pCVar4);
  if (*(char *)((int)local_5dc + 0x32) != '\0') {
LAB_0041cd4b:
    local_5dc[0xf] = (int)local_590 - (int)local_5dc;
    local_5e0 = &PTR_FUN_0046f3e8;
    *local_5dc = &PTR_LAB_0046f3f4;
    local_5dc[0xf] = (int)local_590 - (int)local_5dc;
    local_5d4[0] = &PTR_LAB_0046f3ac;
    if (((local_5b0 != &DAT_00482468) && (local_5b0 != &DAT_004824bc)) &&
       (local_5b0 != &DAT_00482510)) {
      FUN_004118d0((int *)local_5d4);
    }
    local_5d4[0] = &PTR_LAB_0046f370;
    FUN_00404dc0(local_5b8);
    local_5e0 = &PTR_LAB_0046f358;
    *local_5dc = &PTR_LAB_0046f364;
    local_5dc[0xf] = (int)local_5d4 - (int)local_5dc;
    local_590[0] = &PTR_LAB_0046f34c;
    FUN_00454d40(local_590);
    return;
  }
LAB_0041ccdf:
  do {
    FUN_004049b0(local_5dc,local_4c);
    local_41 = DAT_00489668;
    piVar7 = (int *)FUN_00404a00(local_4c);
    cVar3 = (**(code **)(*piVar7 + 0x14))(10);
    FUN_00404dc0(local_4c);
    iVar8 = FUN_0041f300(&local_5e0,(char *)local_550,0x400,cVar3);
    if (*(char *)(*(int *)(iVar8 + 4) + 0x32) != '\0') goto LAB_0041cd4b;
    pbVar12 = &DAT_00470a84;
    pbVar5 = FUN_00450890(local_550);
    pbVar5 = FUN_0044d810((int)pbVar5,pbVar12);
    if (pbVar5 != (byte *)0x0) {
      iVar8 = 8;
      pbVar12 = pbVar5;
      pbVar9 = (byte *)s_texture_00470a88;
      do {
        pbVar10 = pbVar12;
        pbVar11 = pbVar9;
        if (iVar8 == 0) break;
        iVar8 = iVar8 + -1;
        pbVar11 = pbVar9 + 1;
        pbVar10 = pbVar12 + 1;
        bVar2 = *pbVar9;
        bVar1 = *pbVar12;
        pbVar12 = pbVar10;
        pbVar9 = pbVar11;
      } while (bVar1 == bVar2);
      if (pbVar10[-1] != pbVar11[-1]) {
        iVar8 = 0xb;
        pbVar12 = (byte *)s_textureext_00470a90;
        do {
          pbVar9 = pbVar5;
          pbVar10 = pbVar12;
          if (iVar8 == 0) break;
          iVar8 = iVar8 + -1;
          pbVar10 = pbVar12 + 1;
          pbVar9 = pbVar5 + 1;
          bVar2 = *pbVar12;
          bVar1 = *pbVar5;
          pbVar5 = pbVar9;
          pbVar12 = pbVar10;
        } while (bVar1 == bVar2);
        if (pbVar9[-1] != pbVar10[-1]) goto LAB_0041ccdf;
      }
      pbVar5 = FUN_0044d810(0,&DAT_00470a84);
      if (pbVar5 != (byte *)0x0) {
        iVar8 = 5;
        pbVar12 = pbVar5;
        pbVar9 = &DAT_00470a9c;
        do {
          pbVar10 = pbVar12;
          pbVar11 = pbVar9;
          if (iVar8 == 0) break;
          iVar8 = iVar8 + -1;
          pbVar11 = pbVar9 + 1;
          pbVar10 = pbVar12 + 1;
          bVar2 = *pbVar9;
          bVar1 = *pbVar12;
          pbVar12 = pbVar10;
          pbVar9 = pbVar11;
        } while (bVar1 == bVar2);
        if (pbVar10[-1] != pbVar11[-1]) {
          FUN_0044d6b0(local_150,(char *)pbVar5);
          pcVar6 = FUN_0044d7a0((char *)pbVar5,'.');
          if (pcVar6 == (char *)0x0) {
            FUN_0044d700(local_150,&DAT_00470aa4);
          }
          (**(code **)(*param_1 + 0x29c))(param_1,local_150);
          FUN_00412800(param_1,param_2,DAT_00489650);
        }
      }
    }
  } while( true );
}


