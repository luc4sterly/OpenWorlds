// 10026400 FUN_10026400 [Global]
// program: RWDLDD21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_10026400(undefined4 param_1)

{
  byte bVar1;
  int iVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  int iVar3;
  int iVar4;
  longlong lVar5;
  byte local_10c;
  double local_100 [32];
  
  DAT_100393f0 = 0;
  DAT_100392f0 = 0;
  local_100[0] = (double)_DAT_100362ec;
  iVar2 = 1;
  do {
    iVar3 = iVar2 + 1;
    FUN_10029bc2(param_1);
    lVar5 = __ftol();
    (&DAT_100393f0)[iVar2] = (char)lVar5;
    FUN_10029bc2(extraout_ECX);
    lVar5 = __ftol();
    (&DAT_100392f0)[iVar2] = (char)lVar5;
    param_1 = extraout_ECX_00;
    iVar2 = iVar3;
  } while (iVar3 < 0x100);
  iVar3 = 0;
  iVar2 = 0;
  do {
    local_10c = (byte)iVar2;
    if ((*(uint *)(&DAT_100363f0 + (local_10c >> 3 & 0xfffffffc)) & 1 << (local_10c & 0x1f)) != 0) {
      iVar4 = 0;
      if (0 < iVar3) {
        do {
          bVar1 = *(byte *)((int)local_100 + iVar4);
          if ((&DAT_100393f0)[(byte)(&DAT_10039610)[bVar1]] ==
              (&DAT_100393f0)[(byte)(&DAT_10039610)[iVar2]]) {
            if (((&DAT_100393f0)[(byte)(&DAT_10039710)[bVar1]] ==
                 (&DAT_100393f0)[(byte)(&DAT_10039710)[iVar2]]) &&
               ((&DAT_100393f0)[(byte)(&DAT_10039500)[bVar1]] ==
                (&DAT_100393f0)[(byte)(&DAT_10039500)[iVar2]])) break;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < iVar3);
      }
      if (iVar4 == iVar3) {
        *(byte *)((int)local_100 + iVar3) = local_10c;
        iVar3 = iVar3 + 1;
      }
    }
    iVar2 = iVar2 + 1;
    if (0xff < iVar2) {
      FUN_10027dd0(iVar3,(int)local_100);
      return;
    }
  } while( true );
}


