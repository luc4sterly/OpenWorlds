// 0043f580 _Java_NET_worlds_scape_VehicleShape_nativeAnalyzeShape@16 [Global]
// program: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _Java_NET_worlds_scape_VehicleShape_nativeAnalyzeShape_16
               (undefined4 param_1,undefined4 param_2,int param_3,float param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float local_4c;
  float local_48;
  float local_44;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  
                    /* 0x3f580  339  _Java_NET_worlds_scape_VehicleShape_nativeAnalyzeShape@16 */
  if (param_3 == 0) {
    FUN_00402800(s_nVehicleShape_00477d78,0x46);
  }
  FUN_00418900(param_3,&local_20,&local_14);
  local_4c = (local_10 - local_1c) * (float)_DAT_00477d88;
  local_48 = (local_c - local_18) * (float)_DAT_00477d88;
  local_44 = (local_14 - local_20) * (float)_DAT_00477d88;
  if ((((byte)((byte)((ushort)((ushort)(NAN(_DAT_00477d90) || NAN(local_4c)) << 10) >> 8) |
              (byte)((ushort)((ushort)(_DAT_00477d90 == local_4c) << 0xe) >> 8)) == 0x40) ||
      ((byte)((byte)((ushort)((ushort)(NAN(_DAT_00477d90) || NAN(local_48)) << 10) >> 8) |
             (byte)((ushort)((ushort)(_DAT_00477d90 == local_48) << 0xe) >> 8)) == 0x40)) ||
     ((byte)((byte)((ushort)((ushort)(NAN(_DAT_00477d90) || NAN(local_44)) << 10) >> 8) |
            (byte)((ushort)((ushort)(_DAT_00477d90 == local_44) << 0xe) >> 8)) == 0x40)) {
    FUN_0044d5a0(s_Zero_volume_vehicle_shape__model_00477d94);
    local_48 = DAT_00477dc8;
    local_44 = DAT_00477dc8;
    local_4c = DAT_00477dc8;
  }
  _DAT_0049def8 = (local_14 + local_20) * (float)_DAT_00477dd0 * (float)_DAT_00477d88;
  _DAT_0049defc = (local_10 + local_1c) * (float)_DAT_00477dd0 * (float)_DAT_00477d88;
  _DAT_0049df00 = (local_c + local_18) * (float)_DAT_00477dd0 * (float)_DAT_00477d88;
  fVar1 = local_4c * local_4c + local_48 * local_48;
  if ((byte)((byte)((ushort)((ushort)(NAN(_DAT_00477d90) || NAN(fVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)(_DAT_00477d90 == fVar1) << 0xe) >> 8)) == 0x40) {
    FUN_00402800(s_nVehicleShape_00477d78,0x5b);
  }
  fVar2 = local_48 * local_48 + local_44 * local_44;
  if ((byte)((byte)((ushort)((ushort)(NAN(_DAT_00477d90) || NAN(fVar2)) << 10) >> 8) |
            (byte)((ushort)((ushort)(_DAT_00477d90 == fVar2) << 0xe) >> 8)) == 0x40) {
    FUN_00402800(s_nVehicleShape_00477d78,0x5c);
  }
  fVar3 = local_44 * local_44 + local_4c * local_4c;
  if ((byte)((byte)((ushort)((ushort)(NAN(_DAT_00477d90) || NAN(fVar3)) << 10) >> 8) |
            (byte)((ushort)((ushort)(_DAT_00477d90 == fVar3) << 0xe) >> 8)) == 0x40) {
    FUN_00402800(s_nVehicleShape_00477d78,0x5d);
  }
  _DAT_0049df0c = param_4 * _DAT_00477dd8;
  _DAT_0049df04 = _DAT_0049df0c * fVar1;
  _DAT_0049df08 = _DAT_0049df0c * fVar2;
  _DAT_0049df0c = _DAT_0049df0c * fVar3;
  _DAT_0049df10 = local_20 * (float)_DAT_00477d88 - _DAT_0049def8;
  _DAT_0049df14 = local_10 * (float)_DAT_00477d88 - _DAT_0049defc;
  _DAT_0049df18 = local_18 * (float)_DAT_00477d88 - _DAT_0049df00;
  _DAT_0049df1c = local_14 * (float)_DAT_00477d88 - _DAT_0049def8;
  _DAT_0049df2c = local_1c * (float)_DAT_00477d88 - _DAT_0049defc;
  _DAT_0049df20 = _DAT_0049df14;
  _DAT_0049df24 = _DAT_0049df18;
  _DAT_0049df28 = _DAT_0049df10;
  _DAT_0049df30 = _DAT_0049df18;
  _DAT_0049df34 = _DAT_0049df1c;
  _DAT_0049df38 = _DAT_0049df2c;
  _DAT_0049df3c = _DAT_0049df18;
  FUN_0044d5a0(s__Vehicle_shape_analyzed__00477ddb + 1);
  FUN_0044d5a0(s_Center_of_gravity____2f____2f____00477df8);
  FUN_0044d5a0(s_Inertial_tensor___f__f__f_00477e20);
  FUN_0044d5a0(s_Tire_position_0____2f____2f____2_00477e3c);
  FUN_0044d5a0(s_Tire_position_1____2f____2f____2_00477e60);
  FUN_0044d5a0(s_Tire_position_2____2f____2f____2_00477e84);
  FUN_0044d5a0(s_Tire_position_3____2f____2f____2_00477ea8);
  return;
}


