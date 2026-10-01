// 00405811 FUN_00405811 [Global]
// program: run.exe

undefined4 __cdecl FUN_00405811(int param_1)

{
  BYTE *pBVar1;
  byte *pbVar2;
  byte bVar3;
  byte bVar4;
  UINT CodePage;
  UINT *pUVar5;
  BOOL BVar6;
  uint uVar7;
  BYTE *pBVar8;
  int iVar9;
  byte *pbVar10;
  int iVar11;
  byte *pbVar12;
  undefined4 *puVar13;
  _cpinfo local_1c;
  uint local_8;
  
  CodePage = FUN_004059aa(param_1);
  if (CodePage == DAT_0040bbf4) {
    return 0;
  }
  if (CodePage != 0) {
    iVar11 = 0;
    pUVar5 = &DAT_0040b930;
    do {
      if (*pUVar5 == CodePage) {
        puVar13 = &DAT_0040bd20;
        for (iVar9 = 0x40; iVar9 != 0; iVar9 = iVar9 + -1) {
          *puVar13 = 0;
          puVar13 = puVar13 + 1;
        }
        local_8 = 0;
        iVar11 = iVar11 * 0x30;
        *(undefined1 *)puVar13 = 0;
        pbVar12 = (byte *)(iVar11 + 0x40b940);
        do {
          bVar3 = *pbVar12;
          pbVar10 = pbVar12;
          while ((bVar3 != 0 && (bVar3 = pbVar10[1], bVar3 != 0))) {
            uVar7 = (uint)*pbVar10;
            if (uVar7 <= bVar3) {
              bVar4 = (&DAT_0040b928)[local_8];
              do {
                pbVar2 = (byte *)((int)&DAT_0040bd20 + uVar7 + 1);
                *pbVar2 = *pbVar2 | bVar4;
                uVar7 = uVar7 + 1;
              } while (uVar7 <= bVar3);
            }
            pbVar10 = pbVar10 + 2;
            bVar3 = *pbVar10;
          }
          local_8 = local_8 + 1;
          pbVar12 = pbVar12 + 8;
        } while (local_8 < 4);
        DAT_0040bc0c = 1;
        DAT_0040bbf4 = CodePage;
        DAT_0040be24 = FUN_004059f4(CodePage);
        DAT_0040bc00 = *(undefined4 *)(iVar11 + 0x40b934);
        DAT_0040bc04 = *(undefined4 *)(iVar11 + 0x40b938);
        DAT_0040bc08 = *(undefined4 *)(iVar11 + 0x40b93c);
        goto LAB_00405999;
      }
      pUVar5 = pUVar5 + 0xc;
      iVar11 = iVar11 + 1;
    } while (pUVar5 < (UINT *)0x40ba20);
    BVar6 = GetCPInfo(CodePage,&local_1c);
    if (BVar6 == 1) {
      puVar13 = &DAT_0040bd20;
      DAT_0040bbf4 = CodePage;
      for (iVar11 = 0x40; iVar11 != 0; iVar11 = iVar11 + -1) {
        *puVar13 = 0;
        puVar13 = puVar13 + 1;
      }
      *(undefined1 *)puVar13 = 0;
      DAT_0040be24 = 0;
      if (local_1c.MaxCharSize < 2) {
        DAT_0040bc0c = 0;
      }
      else {
        if (local_1c.LeadByte[0] != '\0') {
          pBVar8 = local_1c.LeadByte + 1;
          do {
            bVar3 = *pBVar8;
            if (bVar3 == 0) break;
            for (uVar7 = (uint)pBVar8[-1]; uVar7 <= bVar3; uVar7 = uVar7 + 1) {
              pbVar12 = (byte *)((int)&DAT_0040bd20 + uVar7 + 1);
              *pbVar12 = *pbVar12 | 4;
            }
            pBVar1 = pBVar8 + 1;
            pBVar8 = pBVar8 + 2;
          } while (*pBVar1 != 0);
        }
        uVar7 = 1;
        do {
          pbVar12 = (byte *)((int)&DAT_0040bd20 + uVar7 + 1);
          *pbVar12 = *pbVar12 | 8;
          uVar7 = uVar7 + 1;
        } while (uVar7 < 0xff);
        DAT_0040be24 = FUN_004059f4(CodePage);
        DAT_0040bc0c = 1;
      }
      DAT_0040bc00 = 0;
      DAT_0040bc04 = 0;
      DAT_0040bc08 = 0;
      goto LAB_00405999;
    }
    if (DAT_0040bba8 == 0) {
      return 0xffffffff;
    }
  }
  FUN_00405a27();
LAB_00405999:
  FUN_00405a50();
  return 0;
}


