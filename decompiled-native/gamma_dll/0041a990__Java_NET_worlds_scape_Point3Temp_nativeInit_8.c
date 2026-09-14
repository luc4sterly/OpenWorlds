// 0041a990 _Java_NET_worlds_scape_Point3Temp_nativeInit@8 [Global]
// programa: gamma.dll

void _Java_NET_worlds_scape_Point3Temp_nativeInit_8(int *param_1)

{
  bool bVar1;
  undefined4 uVar2;
  
                    /* 0x1a990  258  _Java_NET_worlds_scape_Point3Temp_nativeInit@8 */
  if (DAT_004895d0 == 0) {
    uVar2 = (**(code **)(*param_1 + 0x18))(param_1,s_NET_worlds_scape_Point3Temp_00470730);
    DAT_004895d0 = (**(code **)(*param_1 + 0x54))(param_1,uVar2);
    if (DAT_004895d0 == 0) {
      FUN_00402800(s_nPoint3_0047074c,0x22);
    }
    DAT_004895d4 = (**(code **)(*param_1 + 0x178))(param_1,DAT_004895d0,&DAT_00470758,&DAT_00470754)
    ;
    DAT_004895d8 = (**(code **)(*param_1 + 0x178))(param_1,DAT_004895d0,&DAT_0047075c,&DAT_00470754)
    ;
    DAT_004895dc = (**(code **)(*param_1 + 0x178))(param_1,DAT_004895d0,&DAT_00470760,&DAT_00470754)
    ;
    bVar1 = false;
    if ((DAT_004895d4 != 0) && (DAT_004895d8 != 0)) {
      bVar1 = true;
    }
    if (!bVar1) {
      FUN_00402800(s_nPoint3_0047074c,0x27);
    }
    if (DAT_004895dc == 0) {
      FUN_00402800(s_nPoint3_0047074c,0x28);
    }
  }
  return;
}


