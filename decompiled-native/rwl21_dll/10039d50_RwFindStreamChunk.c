// 10039d50 RwFindStreamChunk [Global]
// program: RWL21.DLL

undefined4 RwFindStreamChunk(int *param_1,uint param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar2;
  uint local_8;
  uint local_4;
  
  do {
    bVar1 = RwReadStream(param_1,&local_4,4);
    if (CONCAT31(extraout_var,bVar1) == 0) {
      return 0;
    }
    local_4 = (local_4 >> 0x10 | local_4 & 0xff0000) >> 8 |
              (local_4 << 0x10 | local_4 & 0xff00) << 8;
    if (param_2 == local_4) {
      return 1;
    }
    bVar1 = RwReadStream(param_1,&local_8,4);
    if (CONCAT31(extraout_var_00,bVar1) == 0) {
LAB_10039e09:
      bVar1 = false;
    }
    else {
      local_8 = (local_8 & 0xff00 | local_8 << 0x10) << 8 |
                (local_8 & 0xff0000 | local_8 >> 0x10) >> 8;
      if (local_8 == 0) {
        bVar1 = true;
      }
      else {
        iVar2 = RwSeekStream(param_1,local_8);
        bVar1 = true;
        if (iVar2 == 0) goto LAB_10039e09;
      }
    }
    if (!bVar1) {
      return 0;
    }
  } while( true );
}


