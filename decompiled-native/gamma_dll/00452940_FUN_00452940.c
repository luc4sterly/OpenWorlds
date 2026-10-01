// 00452940 FUN_00452940 [Global]
// program: gamma.dll

void * __cdecl FUN_00452940(void *param_1,short param_2)

{
  int *piVar1;
  uint uVar2;
  code *pcVar3;
  undefined4 *puVar4;
  int local_38;
  undefined2 local_34;
  undefined2 uStack_32;
  int local_30;
  undefined2 local_2c;
  int local_28;
  undefined2 local_24;
  int local_20;
  undefined2 local_1c;
  int local_18;
  undefined2 local_14;
  
  if (DAT_0049e56c == '\0') {
    puVar4 = (undefined4 *)&DAT_0049e560;
    pcVar3 = FUN_00407f70;
    piVar1 = FUN_00452480(&DAT_0049e570,&DAT_004817c0,0xffff);
    FUN_00450830(piVar1,pcVar3,puVar4);
    DAT_0049e56c = '\x01';
  }
  if (DAT_0049e584 == '\0') {
    puVar4 = (undefined4 *)&DAT_0049e578;
    pcVar3 = FUN_00407f70;
    piVar1 = FUN_00452480(&DAT_0049e588,&DAT_004817c4,0);
    FUN_00450830(piVar1,pcVar3,puVar4);
    DAT_0049e584 = '\x01';
  }
  uVar2 = (uint)param_2;
  switch(uVar2) {
  case 0:
    if (DAT_0049e6a4 == '\0') {
      puVar4 = (undefined4 *)&DAT_0049e698;
      pcVar3 = FUN_00407f70;
      piVar1 = FUN_00452480(&DAT_0049e6a8,&DAT_00481874,0);
      FUN_00450830(piVar1,pcVar3,puVar4);
      DAT_0049e6a4 = '\x01';
    }
    FUN_00406490(param_1,(undefined4 *)&DAT_0049e6a8);
    *(undefined2 *)((int)param_1 + 4) = DAT_0049e6ac;
    return param_1;
  case 1:
    FUN_00406490(param_1,(undefined4 *)&DAT_0049e588);
    *(undefined2 *)((int)param_1 + 4) = DAT_0049e58c;
    return param_1;
  case 2:
    if (DAT_0049e6bc == '\0') {
      puVar4 = (undefined4 *)&DAT_0049e6b0;
      pcVar3 = FUN_00407f70;
      piVar1 = FUN_00452480(&DAT_0049e6c0,&DAT_00481878,0);
      FUN_00450830(piVar1,pcVar3,puVar4);
      DAT_0049e6bc = '\x01';
    }
    FUN_00406490(param_1,(undefined4 *)&DAT_0049e6c0);
    *(undefined2 *)((int)param_1 + 4) = DAT_0049e6c4;
    return param_1;
  case 3:
    if (DAT_0049e6d4 == '\0') {
      puVar4 = (undefined4 *)&DAT_0049e6c8;
      pcVar3 = FUN_00407f70;
      piVar1 = FUN_00452480(&DAT_0049e6d8,&DAT_0048187c,0);
      FUN_00450830(piVar1,pcVar3,puVar4);
      DAT_0049e6d4 = '\x01';
    }
    FUN_00406490(param_1,(undefined4 *)&DAT_0049e6d8);
    *(undefined2 *)((int)param_1 + 4) = DAT_0049e6dc;
    return param_1;
  case 4:
    if (DAT_0049e6ec == '\0') {
      puVar4 = (undefined4 *)&DAT_0049e6e0;
      pcVar3 = FUN_00407f70;
      piVar1 = FUN_00452480(&DAT_0049e6f0,&DAT_00481880,1);
      FUN_00450830(piVar1,pcVar3,puVar4);
      DAT_0049e6ec = '\x01';
    }
    FUN_00406490(param_1,(undefined4 *)&DAT_0049e6f0);
    *(undefined2 *)((int)param_1 + 4) = DAT_0049e6f4;
    return param_1;
  case 5:
    if (DAT_0049e704 == '\0') {
      puVar4 = (undefined4 *)&DAT_0049e6f8;
      pcVar3 = FUN_00407f70;
      piVar1 = FUN_00452480(&DAT_0049e708,&DAT_00481884,1);
      FUN_00450830(piVar1,pcVar3,puVar4);
      DAT_0049e704 = '\x01';
    }
    FUN_00406490(param_1,(undefined4 *)&DAT_0049e708);
    *(undefined2 *)((int)param_1 + 4) = DAT_0049e70c;
    return param_1;
  case 6:
    if (DAT_0049e71c == '\0') {
      puVar4 = (undefined4 *)&DAT_0049e710;
      pcVar3 = FUN_00407f70;
      piVar1 = FUN_00452480(&DAT_0049e720,&DAT_00481888,1);
      FUN_00450830(piVar1,pcVar3,puVar4);
      DAT_0049e71c = '\x01';
    }
    FUN_00406490(param_1,(undefined4 *)&DAT_0049e720);
    *(undefined2 *)((int)param_1 + 4) = DAT_0049e724;
    return param_1;
  case 7:
    if (DAT_0049e734 == '\0') {
      puVar4 = (undefined4 *)&DAT_0049e728;
      pcVar3 = FUN_00407f70;
      piVar1 = FUN_00452480(&DAT_0049e738,&DAT_0048188c,2);
      FUN_00450830(piVar1,pcVar3,puVar4);
      DAT_0049e734 = '\x01';
    }
    FUN_00406490(param_1,(undefined4 *)&DAT_0049e738);
    *(undefined2 *)((int)param_1 + 4) = DAT_0049e73c;
    return param_1;
  case 8:
    if (DAT_0049e74c == '\0') {
      puVar4 = (undefined4 *)&DAT_0049e740;
      pcVar3 = FUN_00407f70;
      piVar1 = FUN_00452480(&DAT_0049e750,&DAT_00481890,2);
      FUN_00450830(piVar1,pcVar3,puVar4);
      DAT_0049e74c = '\x01';
    }
    FUN_00406490(param_1,(undefined4 *)&DAT_0049e750);
    *(undefined2 *)((int)param_1 + 4) = DAT_0049e754;
    return param_1;
  case 0xffffffc0:
    if (DAT_0049e59c == '\0') {
      puVar4 = (undefined4 *)&DAT_0049e590;
      pcVar3 = FUN_00407f70;
      piVar1 = FUN_00452480(&DAT_0049e5a0,s_54210108624275221700372640043497_004817c8,0xffec);
      FUN_00450830(piVar1,pcVar3,puVar4);
      DAT_0049e59c = '\x01';
    }
    FUN_00406490(param_1,(undefined4 *)&DAT_0049e5a0);
    *(undefined2 *)((int)param_1 + 4) = DAT_0049e5a4;
    return param_1;
  default:
    FUN_00452940(&local_30,(short)((int)((uVar2 + 1) - (uint)(uVar2 < 0x80000000)) >> 1));
    FUN_00406490(&local_38,&local_30);
    _local_34 = CONCAT22(uStack_32,local_2c);
    FUN_00404ed0(&local_30);
    FUN_00406490(&local_28,&local_38);
    local_24 = (undefined2)_local_34;
    FUN_00452730(&local_38,&local_28);
    FUN_00404ed0(&local_28);
    if ((uVar2 & 1 ^ (int)uVar2 >> 0x1f) != (int)uVar2 >> 0x1f) {
      if (param_2 < 1) {
        FUN_00406490(&local_18,(undefined4 *)&DAT_0049e570);
        local_14 = DAT_0049e574;
        FUN_00452730(&local_38,&local_18);
        FUN_00404ed0(&local_18);
      }
      else {
        FUN_00406490(&local_20,(undefined4 *)&DAT_0049e588);
        local_1c = DAT_0049e58c;
        FUN_00452730(&local_38,&local_20);
        FUN_00404ed0(&local_20);
      }
    }
    FUN_00406490(param_1,&local_38);
    *(short *)((int)param_1 + 4) = (short)_local_34;
    FUN_00404ed0(&local_38);
    return param_1;
  case 0xffffffcb:
    if (DAT_0049e5b4 == '\0') {
      puVar4 = (undefined4 *)&DAT_0049e5a8;
      pcVar3 = FUN_00407f70;
      piVar1 = FUN_00452480(&DAT_0049e5b8,s_11102230246251565404236316680908_004817f8,0xfff0);
      FUN_00450830(piVar1,pcVar3,puVar4);
      DAT_0049e5b4 = '\x01';
    }
    FUN_00406490(param_1,(undefined4 *)&DAT_0049e5b8);
    *(undefined2 *)((int)param_1 + 4) = DAT_0049e5bc;
    return param_1;
  case 0xffffffe0:
    if (DAT_0049e5cc == '\0') {
      puVar4 = (undefined4 *)&DAT_0049e5c0;
      pcVar3 = FUN_00407f70;
      piVar1 = FUN_00452480(&DAT_0049e5d0,s_23283064365386962890625_00481820,0xfff6);
      FUN_00450830(piVar1,pcVar3,puVar4);
      DAT_0049e5cc = '\x01';
    }
    break;
  case 0xfffffff0:
    if (DAT_0049e5e4 == '\0') {
      puVar4 = (undefined4 *)&DAT_0049e5d8;
      pcVar3 = FUN_00407f70;
      piVar1 = FUN_00452480(&DAT_0049e5e8,s_152587890625_00481838,0xfffb);
      FUN_00450830(piVar1,pcVar3,puVar4);
      DAT_0049e5e4 = '\x01';
    }
    FUN_00406490(param_1,(undefined4 *)&DAT_0049e5e8);
    *(undefined2 *)((int)param_1 + 4) = DAT_0049e5ec;
    return param_1;
  case 0xfffffff8:
    if (DAT_0049e5fc == '\0') {
      puVar4 = (undefined4 *)&DAT_0049e5f0;
      pcVar3 = FUN_00407f70;
      piVar1 = FUN_00452480(&DAT_0049e600,s_390625_00481848,0xfffd);
      FUN_00450830(piVar1,pcVar3,puVar4);
      DAT_0049e5fc = '\x01';
    }
    FUN_00406490(param_1,(undefined4 *)&DAT_0049e600);
    *(undefined2 *)((int)param_1 + 4) = DAT_0049e604;
    return param_1;
  case 0xfffffff9:
    if (DAT_0049e614 == '\0') {
      puVar4 = (undefined4 *)&DAT_0049e608;
      pcVar3 = FUN_00407f70;
      piVar1 = FUN_00452480(&DAT_0049e618,s_78125_00481850,0xfffd);
      FUN_00450830(piVar1,pcVar3,puVar4);
      DAT_0049e614 = '\x01';
    }
    FUN_00406490(param_1,(undefined4 *)&DAT_0049e618);
    *(undefined2 *)((int)param_1 + 4) = DAT_0049e61c;
    return param_1;
  case 0xfffffffa:
    if (DAT_0049e62c == '\0') {
      puVar4 = (undefined4 *)&DAT_0049e620;
      pcVar3 = FUN_00407f70;
      piVar1 = FUN_00452480(&DAT_0049e630,s_15625_00481858,0xfffe);
      FUN_00450830(piVar1,pcVar3,puVar4);
      DAT_0049e62c = '\x01';
    }
    FUN_00406490(param_1,(undefined4 *)&DAT_0049e630);
    *(undefined2 *)((int)param_1 + 4) = DAT_0049e634;
    return param_1;
  case 0xfffffffb:
    if (DAT_0049e644 == '\0') {
      puVar4 = (undefined4 *)&DAT_0049e638;
      pcVar3 = FUN_00407f70;
      piVar1 = FUN_00452480(&DAT_0049e648,&DAT_00481860,0xfffe);
      FUN_00450830(piVar1,pcVar3,puVar4);
      DAT_0049e644 = '\x01';
    }
    FUN_00406490(param_1,(undefined4 *)&DAT_0049e648);
    *(undefined2 *)((int)param_1 + 4) = DAT_0049e64c;
    return param_1;
  case 0xfffffffc:
    if (DAT_0049e65c == '\0') {
      puVar4 = (undefined4 *)&DAT_0049e650;
      pcVar3 = FUN_00407f70;
      piVar1 = FUN_00452480(&DAT_0049e660,&DAT_00481868,0xfffe);
      FUN_00450830(piVar1,pcVar3,puVar4);
      DAT_0049e65c = '\x01';
    }
    FUN_00406490(param_1,(undefined4 *)&DAT_0049e660);
    *(undefined2 *)((int)param_1 + 4) = DAT_0049e664;
    return param_1;
  case 0xfffffffd:
    if (DAT_0049e674 == '\0') {
      puVar4 = (undefined4 *)&DAT_0049e668;
      pcVar3 = FUN_00407f70;
      piVar1 = FUN_00452480(&DAT_0049e678,&DAT_0048186c,0xffff);
      FUN_00450830(piVar1,pcVar3,puVar4);
      DAT_0049e674 = '\x01';
    }
    FUN_00406490(param_1,(undefined4 *)&DAT_0049e678);
    *(undefined2 *)((int)param_1 + 4) = DAT_0049e67c;
    return param_1;
  case 0xfffffffe:
    if (DAT_0049e68c == '\0') {
      puVar4 = (undefined4 *)&DAT_0049e680;
      pcVar3 = FUN_00407f70;
      piVar1 = FUN_00452480(&DAT_0049e690,&DAT_00481870,0xffff);
      FUN_00450830(piVar1,pcVar3,puVar4);
      DAT_0049e68c = '\x01';
    }
    FUN_00406490(param_1,(undefined4 *)&DAT_0049e690);
    *(undefined2 *)((int)param_1 + 4) = DAT_0049e694;
    return param_1;
  case 0xffffffff:
    FUN_00406490(param_1,(undefined4 *)&DAT_0049e570);
    *(undefined2 *)((int)param_1 + 4) = DAT_0049e574;
    return param_1;
  }
  FUN_00406490(param_1,(undefined4 *)&DAT_0049e5d0);
  *(undefined2 *)((int)param_1 + 4) = DAT_0049e5d4;
  return param_1;
}


