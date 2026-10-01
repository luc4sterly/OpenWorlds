// 1005ac90 __setmbcp [Global]
// program: RWDL8D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __setmbcp
   
   Library: Visual Studio 1998 Release */

int __cdecl __setmbcp(int _CodePage)

{
  byte *pbVar1;
  byte bVar2;
  UINT CodePage;
  UINT *pUVar3;
  BOOL BVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  BYTE *pBVar8;
  byte *pbVar9;
  undefined4 *puVar10;
  int local_18;
  _cpinfo local_14;
  
  __lock(0x19);
  CodePage = getSystemCP(_CodePage);
  if (DAT_1007580c == CodePage) {
    FUN_1005d3f0(0x19);
    return 0;
  }
  if (CodePage == 0) {
    setSBCS();
    FUN_1005d3f0(0x19);
    return 0;
  }
  local_18 = 0;
  pUVar3 = &DAT_10075830;
  do {
    if (*pUVar3 == CodePage) {
      uVar5 = 0;
      puVar10 = &DAT_10075708;
      for (iVar6 = 0x40; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar10 = 0;
        puVar10 = puVar10 + 1;
      }
      *(undefined1 *)puVar10 = 0;
      do {
        pbVar9 = &DAT_10075840 + (local_18 * 6 + uVar5) * 8;
        bVar2 = *pbVar9;
        while ((bVar2 != 0 && (pbVar9[1] != 0))) {
          uVar7 = (uint)*pbVar9;
          if (uVar7 <= pbVar9[1]) {
            bVar2 = (&DAT_10075828)[uVar5];
            do {
              pbVar1 = (byte *)((int)&DAT_10075708 + uVar7 + 1);
              *pbVar1 = *pbVar1 | bVar2;
              uVar7 = uVar7 + 1;
            } while (uVar7 <= pbVar9[1]);
          }
          pbVar9 = pbVar9 + 2;
          bVar2 = *pbVar9;
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < 4);
      DAT_1007580c = CodePage;
      _DAT_10075810 = _CPtoLCID(CodePage);
      DAT_1007581c = *(undefined4 *)(&DAT_10075838 + local_18 * 0x30);
      DAT_10075818 = *(undefined4 *)(&DAT_10075834 + local_18 * 0x30);
      DAT_10075820 = *(undefined4 *)(local_18 * 0x30 + 0x1007583c);
      FUN_1005d3f0(0x19);
      return 0;
    }
    pUVar3 = pUVar3 + 0xc;
    local_18 = local_18 + 1;
  } while (pUVar3 < &DAT_10075920);
  BVar4 = GetCPInfo(CodePage,&local_14);
  if (BVar4 == 1) {
    puVar10 = &DAT_10075708;
    for (iVar6 = 0x40; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar10 = 0;
      puVar10 = puVar10 + 1;
    }
    *(undefined1 *)puVar10 = 0;
    if (local_14.MaxCharSize < 2) {
      _DAT_10075810 = 0;
      DAT_1007580c = 0;
    }
    else {
      pBVar8 = local_14.LeadByte;
      while ((local_14.LeadByte[0] != 0 && (pBVar8[1] != 0))) {
        uVar5 = (uint)*pBVar8;
        if (uVar5 <= pBVar8[1]) {
          do {
            pbVar9 = (byte *)((int)&DAT_10075708 + uVar5 + 1);
            *pbVar9 = *pbVar9 | 4;
            uVar5 = uVar5 + 1;
          } while (uVar5 <= pBVar8[1]);
        }
        pBVar8 = pBVar8 + 2;
        local_14.LeadByte[0] = *pBVar8;
      }
      uVar5 = 1;
      do {
        pbVar9 = (byte *)((int)&DAT_10075708 + uVar5 + 1);
        *pbVar9 = *pbVar9 | 8;
        uVar5 = uVar5 + 1;
      } while (uVar5 < 0xff);
      DAT_1007580c = CodePage;
      _DAT_10075810 = _CPtoLCID(CodePage);
    }
    DAT_10075818 = 0;
    DAT_1007581c = 0;
    DAT_10075820 = 0;
    FUN_1005d3f0(0x19);
    return 0;
  }
  if (DAT_10075824 == 0) {
    FUN_1005d3f0(0x19);
    return -1;
  }
  setSBCS();
  FUN_1005d3f0(0x19);
  return 0;
}


