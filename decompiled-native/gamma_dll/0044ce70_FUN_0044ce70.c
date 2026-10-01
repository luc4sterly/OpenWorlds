// 0044ce70 FUN_0044ce70 [Global]
// program: gamma.dll

byte * __cdecl FUN_0044ce70(undefined *param_1,undefined4 param_2,char *param_3,uint *param_4)

{
  byte *pbVar1;
  uint *puVar2;
  char cVar3;
  byte bVar4;
  int *piVar5;
  char *pcVar6;
  int iVar7;
  uint uVar8;
  byte *pbVar9;
  int iVar10;
  undefined4 extraout_EDX;
  undefined4 uVar11;
  byte *pbVar12;
  char *pcVar13;
  byte *pbVar14;
  byte *pbVar15;
  bool bVar16;
  undefined8 uVar17;
  uint uStack_254;
  byte *local_248;
  char *local_244;
  undefined4 local_238;
  uint uStack_234;
  int iStack_230;
  byte *pbStack_22c;
  uint uStack_228;
  uint uStack_224;
  byte local_21c [511];
  byte abStack_1d [13];
  
  abStack_1d[3] = ' ';
  local_244 = param_3;
  local_248 = (byte *)0x0;
  pbVar1 = abStack_1d + 1;
  do {
    while( true ) {
      if (*local_244 == '\0') {
        return local_248;
      }
      pcVar6 = FUN_0044d7a0(local_244,'%');
      if (pcVar6 == (char *)0x0) {
        iVar10 = -1;
        pcVar6 = local_244;
        goto code_r0x0044cede;
      }
      iVar10 = (int)pcVar6 - (int)local_244;
      local_248 = local_248 + iVar10;
      uVar11 = extraout_EDX;
      if (iVar10 != 0) {
        uVar17 = (*(code *)param_1)(param_2,local_244,iVar10);
        uVar11 = (undefined4)((ulonglong)uVar17 >> 0x20);
        if ((int)uVar17 == 0) {
          return (byte *)0xffffffff;
        }
      }
      uVar17 = FUN_0044bf00(&local_238,uVar11,(int)pcVar6,(int *)&param_4,&local_238);
      local_244 = (char *)uVar17;
      uVar8 = uStack_234 >> 8 & 0xff;
      if (uVar8 != 0x25) break;
      pbVar9 = local_21c;
      local_21c[0] = 0x25;
      pbVar15 = (byte *)0x1;
LAB_0044d3c0:
      pbVar12 = pbVar15;
      if ((char)local_238 != '\0') {
        if ((char)local_238 == '\x02') {
          abStack_1d[3] = '0';
        }
        else {
          abStack_1d[3] = ' ';
        }
        bVar4 = *pbVar9;
        if ((((bVar4 == 0x2b) || (bVar4 == 0x2d)) || (bVar4 == 0x20)) && (abStack_1d[3] == '0')) {
          iVar10 = (*(code *)param_1)(param_2,pbVar9,1);
          if (iVar10 == 0) {
            return (byte *)0xffffffff;
          }
          pbVar9 = pbVar9 + 1;
          pbVar12 = pbVar15 + -1;
        }
        for (; (int)pbVar15 < iStack_230; pbVar15 = pbVar15 + 1) {
          iVar10 = (*(code *)param_1)(param_2,abStack_1d + 3,1);
          if (iVar10 == 0) {
            return (byte *)0xffffffff;
          }
        }
      }
      if ((pbVar12 != (byte *)0x0) &&
         (iVar10 = (*(code *)param_1)(param_2,pbVar9,pbVar12), iVar10 == 0)) {
        return (byte *)0xffffffff;
      }
      if ((char)local_238 == '\0') {
        for (; (int)pbVar15 < iStack_230; pbVar15 = pbVar15 + 1) {
          abStack_1d[4] = 0x20;
          iVar10 = (*(code *)param_1)(param_2,abStack_1d + 4,1);
          if (iVar10 == 0) {
            return (byte *)0xffffffff;
          }
        }
      }
      local_248 = local_248 + (int)pbVar15;
    }
    if (uVar8 == 0x41) {
LAB_0044d1db:
      uVar17 = *(undefined8 *)param_4;
      param_4 = param_4 + 2;
      pbVar9 = (byte *)FUN_0044c630((int)uVar17,(uint)((ulonglong)uVar17 >> 0x20),(int)pbVar1,
                                    local_238,uStack_234,iStack_230,(uint)pbStack_22c);
      if (pbVar9 != (byte *)0x0) {
        pbVar15 = abStack_1d + -(int)pbVar9;
        goto LAB_0044d3c0;
      }
LAB_0044d373:
      iVar10 = -1;
      pcVar13 = pcVar6;
      goto code_r0x0044d37c;
    }
    if (uVar8 - 0x45 < 3) {
LAB_0044d18e:
      uVar17 = *(undefined8 *)param_4;
      param_4 = param_4 + 2;
      pbVar9 = FUN_0044c980((int)uVar17,(uint)((ulonglong)uVar17 >> 0x20),(int)pbVar1,local_238,
                            uStack_234,iStack_230,(uint)pbStack_22c);
      if (pbVar9 == (byte *)0x0) goto LAB_0044d373;
      pbVar15 = abStack_1d + -(int)pbVar9;
      goto LAB_0044d3c0;
    }
    if (uVar8 == 0x58) goto LAB_0044d0b7;
    if (uVar8 == 0x61) goto LAB_0044d1db;
    if (uVar8 == 99) {
      pbVar9 = local_21c;
      local_21c[0] = (byte)*param_4;
      pbVar15 = (byte *)0x1;
      param_4 = param_4 + 1;
      goto LAB_0044d3c0;
    }
    if (uVar8 == 100) {
LAB_0044cff0:
      if ((char)uStack_234 == '\x03') {
        uStack_254 = *param_4;
LAB_0044d031:
        param_4 = param_4 + 1;
      }
      else {
        if ((char)uStack_234 != '\x04') {
          uStack_254 = *param_4;
          goto LAB_0044d031;
        }
        uStack_228 = *param_4;
        uStack_224 = param_4[1];
        param_4 = param_4 + 2;
      }
      if ((char)uStack_234 == '\x02') {
        uStack_254 = (uint)(short)uStack_254;
      }
      if ((char)uStack_234 == '\x01') {
        uStack_254 = (uint)(char)uStack_254;
      }
      if ((char)uStack_234 == '\x04') {
        pbVar9 = (byte *)FUN_0044c3f0(uStack_228,uStack_224,(int)pbVar1,local_238,uStack_234,
                                      iStack_230,(int)pbStack_22c);
      }
      else {
        pbVar9 = (byte *)FUN_0044c240(uStack_254,(int)pbVar1,local_238,uStack_234,iStack_230,
                                      (int)pbStack_22c);
      }
      if (pbVar9 != (byte *)0x0) {
        pbVar15 = abStack_1d + -(int)pbVar9;
        goto LAB_0044d3c0;
      }
      goto LAB_0044d373;
    }
    if (uVar8 - 0x65 < 3) goto LAB_0044d18e;
    if (uVar8 == 0x69) goto LAB_0044cff0;
    if (uVar8 != 0x6e) {
      if (uVar8 != 0x6f) {
        if (uVar8 == 0x73) {
          if ((char)uStack_234 == '\x06') {
            pcVar13 = (char *)*param_4;
            if (pcVar13 == (char *)0x0) {
              pcVar13 = &DAT_00480970;
            }
            param_4 = param_4 + 1;
            iVar10 = FUN_004584f0((char *)local_21c,pcVar13,0x200);
            if (iVar10 < 0) goto LAB_0044d373;
            pbVar9 = local_21c;
          }
          else {
            pbVar9 = (byte *)*param_4;
            param_4 = param_4 + 1;
          }
          if (pbVar9 == (byte *)0x0) {
            pbVar9 = &DAT_00480974;
          }
          if (local_238._3_1_ == '\0') {
            if (local_238._2_1_ == '\0') {
              iVar10 = -1;
              pbVar15 = pbVar9;
              do {
                if (iVar10 == 0) break;
                iVar10 = iVar10 + -1;
                bVar4 = *pbVar15;
                pbVar15 = pbVar15 + 1;
              } while (bVar4 != 0);
              pbVar15 = (byte *)(-2 - iVar10);
            }
            else {
              bVar16 = pbVar9 == pbStack_22c;
              pbVar12 = pbStack_22c;
              pbVar15 = pbVar9;
              do {
                pbVar14 = pbVar15;
                if (pbVar12 == (byte *)0x0) break;
                pbVar12 = pbVar12 + -1;
                pbVar14 = pbVar15 + 1;
                bVar16 = *pbVar15 == 0;
                pbVar15 = pbVar14;
              } while (!bVar16);
              if (bVar16) {
                pbVar12 = pbVar14 + -1;
              }
              pbVar15 = pbStack_22c;
              if (pbVar12 != (byte *)0x0) {
                pbVar15 = pbVar12 + -(int)pbVar9;
              }
            }
          }
          else {
            pbVar15 = (byte *)(uint)*pbVar9;
            pbVar9 = pbVar9 + 1;
            if ((local_238._2_1_ != '\0') && ((int)pbStack_22c < (int)pbVar15)) {
              pbVar15 = pbStack_22c;
            }
          }
          goto LAB_0044d3c0;
        }
        if ((uVar8 != 0x75) && (uVar8 != 0x78)) goto LAB_0044d373;
      }
LAB_0044d0b7:
      if ((char)uStack_234 == '\x03') {
        uStack_254 = *param_4;
LAB_0044d0fc:
        param_4 = param_4 + 1;
      }
      else {
        if ((char)uStack_234 != '\x04') {
          uStack_254 = *param_4;
          goto LAB_0044d0fc;
        }
        uStack_228 = *param_4;
        uStack_224 = param_4[1];
        param_4 = param_4 + 2;
      }
      if ((char)uStack_234 == '\x02') {
        uStack_254 = uStack_254 & 0xffff;
      }
      if ((char)uStack_234 == '\x01') {
        uStack_254 = uStack_254 & 0xff;
      }
      if ((char)uStack_234 == '\x04') {
        pbVar9 = (byte *)FUN_0044c3f0(uStack_228,uStack_224,(int)pbVar1,local_238,uStack_234,
                                      iStack_230,(int)pbStack_22c);
      }
      else {
        pbVar9 = (byte *)FUN_0044c240(uStack_254,(int)pbVar1,local_238,uStack_234,iStack_230,
                                      (int)pbStack_22c);
      }
      if (pbVar9 != (byte *)0x0) {
        pbVar15 = abStack_1d + -(int)pbVar9;
        goto LAB_0044d3c0;
      }
      goto LAB_0044d373;
    }
    puVar2 = param_4 + 1;
    piVar5 = (int *)*param_4;
    param_4 = puVar2;
    switch(uStack_234 & 0xff) {
    case 0:
      *piVar5 = (int)local_248;
      break;
    case 1:
      break;
    case 2:
      *(undefined2 *)piVar5 = local_248._0_2_;
      break;
    case 3:
      *piVar5 = (int)local_248;
      break;
    case 4:
      *piVar5 = (int)local_248;
      piVar5[1] = (int)local_248 >> 0x1f;
    }
  } while( true );
  while( true ) {
    iVar10 = iVar10 + -1;
    cVar3 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    if (cVar3 == '\0') break;
code_r0x0044cede:
    if (iVar10 == 0) break;
  }
  iVar10 = -2 - iVar10;
  if ((iVar10 != 0) && (iVar7 = (*(code *)param_1)(param_2,local_244,iVar10), iVar7 == 0)) {
    return (byte *)0xffffffff;
  }
  return local_248 + iVar10;
  while( true ) {
    iVar10 = iVar10 + -1;
    cVar3 = *pcVar13;
    pcVar13 = pcVar13 + 1;
    if (cVar3 == '\0') break;
code_r0x0044d37c:
    if (iVar10 == 0) break;
  }
  iVar10 = -2 - iVar10;
  if ((iVar10 != 0) && (iVar7 = (*(code *)param_1)(param_2,pcVar6,iVar10), iVar7 == 0)) {
    return (byte *)0xffffffff;
  }
  return local_248 + iVar10;
}


