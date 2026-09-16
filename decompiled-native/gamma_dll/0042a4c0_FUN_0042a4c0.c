// 0042a4c0 FUN_0042a4c0 [Global]
// programa: gamma.dll

undefined4 __fastcall FUN_0042a4c0(int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  byte bVar4;
  byte *pbVar5;
  int iVar6;
  byte *pbStack_14;
  
  if (param_1[0xe] != 0) {
    param_1[0xe] = 0;
    if (param_1[0xf] == 0) {
      param_1[0xf] = 1;
    }
    if (param_1[8] == 0) {
      param_1[8] = (int)&DAT_0049f9ac;
    }
    if (param_1[9] == 0) {
      param_1[9] = (int)&DAT_0049eda8;
    }
    if (param_1[10] == 0) {
      iVar2 = (**(code **)(*param_1 + 8))(param_1[8],0x4000);
      param_1[10] = iVar2;
    }
    FUN_0042ae30((int)param_1);
  }
switchD_0042a64e_caseD_1:
  pbVar5 = (byte *)param_1[0xd];
  *pbVar5 = *(byte *)(param_1 + 0xb);
  iVar2 = param_1[0xf];
  param_1[0x14] = param_1[0x13];
  piVar1 = (int *)param_1[0x14];
  param_1[0x14] = param_1[0x14] + 4;
  *piVar1 = iVar2;
  pbStack_14 = pbVar5;
LAB_0042a540:
  do {
    bVar4 = (byte)u_________________0123456789_<_>___004739ba[(uint)*pbVar5 * 2 + 0x3b];
    while (iVar2 != *(short *)(&DAT_004740b4 +
                              ((uint)bVar4 + (int)*(short *)(&DAT_00473e98 + iVar2 * 2)) * 2)) {
      iVar2 = (int)*(short *)(&DAT_00473f30 + iVar2 * 2);
      if (0x48 < iVar2) {
        bVar4 = (&DAT_00473e30)[(uint)bVar4 * 4];
      }
    }
    piVar1 = (int *)param_1[0x14];
    pbVar5 = pbVar5 + 1;
    iVar2 = (int)*(short *)(&DAT_00473fc8 +
                           ((uint)bVar4 + (int)*(short *)(&DAT_00473e98 + iVar2 * 2)) * 2);
    param_1[0x14] = param_1[0x14] + 4;
    *piVar1 = iVar2;
  } while (*(short *)(&DAT_00473e98 + iVar2 * 2) != 0x5b);
LAB_0042a5b8:
  param_1[0x14] = param_1[0x14] + -4;
  iVar2 = *(int *)param_1[0x14];
  param_1[0x18] = (int)*(short *)(&DAT_0047399c + iVar2 * 2);
  while ((iVar6 = param_1[0x18], iVar6 == 0 || ((short)(&DAT_0047399e)[iVar2] <= iVar6))) {
    pbVar5 = pbVar5 + -1;
    param_1[0x14] = param_1[0x14] + -4;
    iVar2 = *(int *)param_1[0x14];
    param_1[0x18] = (int)*(short *)(&DAT_0047399c + iVar2 * 2);
  }
  iVar2 = (int)*(short *)(&DAT_004738d8 + iVar6 * 2);
  param_1[0x15] = (int)pbVar5;
  param_1[1] = (int)pbStack_14;
  param_1[2] = (int)pbVar5 - (int)pbStack_14;
  *(byte *)(param_1 + 0xb) = *pbVar5;
  *pbVar5 = 0;
  param_1[0xd] = (int)pbVar5;
  if (iVar2 != 0x11) {
    for (iVar6 = 0; iVar6 < param_1[2]; iVar6 = iVar6 + 1) {
      if (*(char *)(param_1[1] + iVar6) == '\n') {
        param_1[3] = param_1[3] + 1;
      }
    }
  }
  do {
    switch(iVar2) {
    case 1:
    case 0xe:
      goto switchD_0042a64e_caseD_1;
    case 2:
      return 0x101;
    case 3:
      return 0x102;
    case 4:
      return 0x103;
    case 5:
      return 0x104;
    case 6:
      return 0x105;
    case 7:
      return 0x106;
    case 8:
      return 0x107;
    case 9:
      return 0x108;
    case 10:
      return 0x10b;
    case 0xb:
      return 0x10c;
    case 0xc:
      DAT_0049fe04 = FUN_00454250(param_1[1]);
      return 0x109;
    case 0xd:
      FUN_0044d6d0(&DAT_0049eeb8,(char *)param_1[1],0x3ff);
      DAT_0049f2b7 = 0;
      return 0x10a;
    case 0xf:
      FUN_0044d6d0(&DAT_0049eeb8,(char *)param_1[1],0x3ff);
      DAT_0049f2b7 = 0;
      return 0;
    case 0x10:
      (**(code **)(*param_1 + 0x20))(param_1[1],param_1[2]);
      goto switchD_0042a64e_caseD_1;
    case 0x11:
      iVar2 = param_1[1];
      *pbVar5 = *(byte *)(param_1 + 0xb);
      if (*(int *)(param_1[10] + 0x24) == 0) {
        param_1[0xc] = *(int *)(param_1[10] + 0x10);
        *(int *)param_1[10] = param_1[8];
        *(undefined4 *)(param_1[10] + 0x24) = 1;
      }
      if ((uint)param_1[0xd] <= (uint)(*(int *)(param_1[10] + 4) + param_1[0xc])) {
        param_1[0xd] = (int)(pbVar5 + param_1[1] + (-1 - iVar2));
        iVar2 = FUN_0042ac80((int)param_1);
        iVar2 = FUN_0042ad20(param_1,iVar2);
        pbStack_14 = (byte *)param_1[1];
        if (iVar2 == 0) {
          pbVar5 = (byte *)param_1[0xd];
          goto LAB_0042a5b8;
        }
        param_1[0xd] = param_1[0xd] + 1;
        pbVar5 = (byte *)param_1[0xd];
        goto LAB_0042a540;
      }
      break;
    case 0x12:
      return 0xffffffff;
    default:
      (**(code **)(*param_1 + 0x24))(s_fatal_flex_scanner_internal_erro_0047425c);
      goto switchD_0042a64e_caseD_1;
    }
    uVar3 = FUN_0042aa90(param_1);
    switch(uVar3) {
    case 0:
      param_1[0xd] = (int)(pbVar5 + param_1[1] + (-1 - iVar2));
      iVar2 = FUN_0042ac80((int)param_1);
      pbStack_14 = (byte *)param_1[1];
      pbVar5 = (byte *)param_1[0xd];
      goto LAB_0042a540;
    case 1:
      param_1[0x10] = 0;
      param_1[0xd] = param_1[1];
      iVar2 = ((int)(param_1[0xf] - (uint)(param_1[0xf] - 1U < 0x80000000)) >> 1) + 0x12;
      break;
    case 2:
      goto switchD_0042a7e8_caseD_2;
    default:
      goto switchD_0042a64e_caseD_1;
    }
  } while( true );
switchD_0042a7e8_caseD_2:
  param_1[0xd] = *(int *)(param_1[10] + 4) + param_1[0xc];
  FUN_0042ac80((int)param_1);
  pbStack_14 = (byte *)param_1[1];
  pbVar5 = (byte *)param_1[0xd];
  goto LAB_0042a5b8;
}


