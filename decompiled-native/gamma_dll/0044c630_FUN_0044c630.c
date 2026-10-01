// 0044c630 FUN_0044c630 [Global]
// program: gamma.dll

/* WARNING: Restarted to delay deadcode elimination for space: stack */

char * __cdecl
FUN_0044c630(int param_1,uint param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,uint param_7)

{
  int iVar1;
  int iVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  uint uVar6;
  char *pcVar7;
  byte bVar8;
  char cVar9;
  char *pcVar10;
  uint uVar11;
  ushort local_60;
  undefined4 local_50;
  undefined1 local_44 [2];
  undefined2 local_42;
  char local_40 [5];
  char local_3b;
  
  uVar6 = param_7;
  iVar2 = param_3;
  iVar1 = param_1;
  cVar5 = param_5._1_1_;
  cVar4 = param_4._3_1_;
  cVar3 = param_4._1_1_;
  if (0x1fd < (int)param_7) {
    return (char *)0x0;
  }
  local_44[0] = 0;
  local_42 = 0x20;
  FUN_00458390(local_44,param_1,param_2,local_40);
  local_60 = (ushort)iVar1;
  if (local_3b != 'I') {
    if (local_3b != 'N') {
      pcVar7 = FUN_0044c240((int)((short)(local_60 & 0x7ff0) >> 4) - 0x3ff,iVar2,0x101,
                            CONCAT22((short)((uint)local_50 >> 0x10),0x6400),0,1);
      if (cVar5 == 'a') {
        pcVar7[-1] = 'p';
      }
      else {
        pcVar7[-1] = 'P';
      }
      pcVar7 = pcVar7 + -1;
      for (uVar11 = uVar6; 0 < (int)uVar11; uVar11 = uVar11 - 1) {
        bVar8 = *(byte *)((int)&param_1 +
                         ((int)((uVar11 + 1) - (uint)(uVar11 < 0x80000000)) >> 1) + 1);
        if ((uVar11 & 1 ^ (int)uVar11 >> 0x1f) == (int)uVar11 >> 0x1f) {
          bVar8 = (char)bVar8 >> 4;
        }
        bVar8 = bVar8 & 0xf;
        if (bVar8 < 10) {
          cVar9 = bVar8 + 0x30;
        }
        else if (cVar5 == 'a') {
          cVar9 = bVar8 + 0x57;
        }
        else {
          cVar9 = bVar8 + 0x37;
        }
        pcVar7 = pcVar7 + -1;
        *pcVar7 = cVar9;
      }
      if ((uVar6 != 0) || (cVar4 != '\0')) {
        pcVar7 = pcVar7 + -1;
        *pcVar7 = '.';
      }
      pcVar7[-1] = '1';
      if (cVar5 == 'a') {
        pcVar7[-2] = 'x';
      }
      else {
        pcVar7[-2] = 'X';
      }
      pcVar10 = pcVar7 + -3;
      *pcVar10 = '0';
      if (((int)(short)local_60 & 0x8000U) == 0) {
        if (cVar3 == '\x01') {
          pcVar10 = pcVar7 + -4;
          *pcVar10 = '+';
        }
        else if (cVar3 == '\x02') {
          pcVar10 = pcVar7 + -4;
          *pcVar10 = ' ';
        }
      }
      else {
        pcVar10 = pcVar7 + -4;
        *pcVar10 = '-';
      }
      return pcVar10;
    }
    if (((int)(char)param_1 & 0x80U) == 0) {
      pcVar7 = (char *)(iVar2 + -4);
      if (cVar5 == 'A') {
        *(undefined4 *)pcVar7 = DAT_00480960;
      }
      else {
        *(undefined4 *)pcVar7 = DAT_00480964;
      }
    }
    else {
      pcVar7 = (char *)(iVar2 + -5);
      if (cVar5 == 'A') {
        *(undefined4 *)pcVar7 = DAT_00480950;
        *(undefined1 *)(iVar2 + -1) = DAT_00480954;
      }
      else {
        *(undefined4 *)pcVar7 = DAT_00480958;
        *(undefined1 *)(iVar2 + -1) = DAT_0048095c;
      }
    }
    return pcVar7;
  }
  if (((int)(short)local_60 & 0x8000U) == 0) {
    pcVar7 = (char *)(iVar2 + -4);
    if (cVar5 == 'A') {
      *(undefined4 *)pcVar7 = DAT_00480948;
    }
    else {
      *(undefined4 *)pcVar7 = DAT_0048094c;
    }
  }
  else {
    pcVar7 = (char *)(iVar2 + -5);
    if (cVar5 == 'A') {
      *(undefined4 *)pcVar7 = DAT_00480938;
      *(undefined1 *)(iVar2 + -1) = DAT_0048093c;
    }
    else {
      *(undefined4 *)pcVar7 = DAT_00480940;
      *(undefined1 *)(iVar2 + -1) = DAT_00480944;
    }
  }
  return pcVar7;
}


