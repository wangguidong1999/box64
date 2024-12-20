#if !(defined(GO) && defined(GOM) && defined(GO2) && defined(DATA))
#error Meh...
#endif

GO(gst_mikey_message_add_cs_srtp, iFpCuu)
GO(gst_mikey_message_add_payload, iFpp)
GO(gst_mikey_message_add_pke, iFpuWp)
GO(gst_mikey_message_add_rand, iFpCp)
GO(gst_mikey_message_add_rand_len, iFpC)
GO(gst_mikey_message_add_t, iFpup)
GO(gst_mikey_message_add_t_now_ntp_utc, iFp)
GO(gst_mikey_message_base64_encode, pFp)
GO(gst_mikey_message_find_payload, pFpuu)
GO(gst_mikey_message_get_cs_srtp, pFpu)
GO(gst_mikey_message_get_n_cs, uFp)
GO(gst_mikey_message_get_n_payloads, uFp)
GO(gst_mikey_message_get_payload, pFpu)
GO(gst_mikey_message_get_type, LFv)
GO(gst_mikey_message_insert_cs_srtp, iFpip)
GO(gst_mikey_message_insert_payload, iFpup)
GO(gst_mikey_message_new, pFv)
GO(gst_mikey_message_new_from_bytes, pFppp)
GO(gst_mikey_message_new_from_caps, pFp)
GO(gst_mikey_message_new_from_data, pFpLpp)
GO(gst_mikey_message_remove_cs_srtp, iFpi)
GO(gst_mikey_message_remove_payload, iFpu)
GO(gst_mikey_message_replace_cs_srtp, iFpip)
GO(gst_mikey_message_replace_payload, iFpup)
GO(gst_mikey_message_set_info, iFpCiiuuu)
GO(gst_mikey_message_to_bytes, pFppp)
GO(gst_mikey_message_to_caps, iFpp)
GO(gst_mikey_payload_get_type, LFv)
GO(gst_mikey_payload_kemac_add_sub, iFpp)
GO(gst_mikey_payload_kemac_get_n_sub, uFp)
GO(gst_mikey_payload_kemac_get_sub, pFpu)
GO(gst_mikey_payload_kemac_remove_sub, iFpu)
GO(gst_mikey_payload_kemac_set, iFpuu)
GO(gst_mikey_payload_key_data_set_interval, iFpCpCp)
GO(gst_mikey_payload_key_data_set_key, iFpuWp)
GO(gst_mikey_payload_key_data_set_salt, iFpWp)
GO(gst_mikey_payload_key_data_set_spi, iFpCp)
GO(gst_mikey_payload_new, pFu)
GO(gst_mikey_payload_pke_set, iFpuWp)
GO(gst_mikey_payload_rand_set, iFpCp)
GO(gst_mikey_payload_sp_add_param, iFpCCp)
GO(gst_mikey_payload_sp_get_n_params, uFp)
GO(gst_mikey_payload_sp_get_param, pFpu)
GO(gst_mikey_payload_sp_remove_param, iFpu)
GO(gst_mikey_payload_sp_set, iFpuu)
GO(gst_mikey_payload_t_set, iFpup)
GO(gst_sdp_address_is_multicast, iFppp)
GO(gst_sdp_attribute_clear, iFp)
GO(gst_sdp_attribute_set, iFppp)
GO(gst_sdp_bandwidth_clear, iFp)
GO(gst_sdp_bandwidth_set, iFppu)
GO(gst_sdp_connection_clear, iFp)
GO(gst_sdp_connection_set, iFppppuu)
GO(gst_sdp_make_keymgmt, pFpp)
GO(gst_sdp_media_add_attribute, iFppp)
GO(gst_sdp_media_add_bandwidth, iFppu)
GO(gst_sdp_media_add_connection, iFppppuu)
GO(gst_sdp_media_add_format, iFpp)
GO(gst_sdp_media_as_text, pFp)
GO(gst_sdp_media_attributes_len, uFp)
GO(gst_sdp_media_attributes_to_caps, iFpp)
GO(gst_sdp_media_bandwidths_len, uFp)
GO(gst_sdp_media_connections_len, uFp)
GO(gst_sdp_media_copy, iFpp)
GO(gst_sdp_media_formats_len, uFp)
GO(gst_sdp_media_free, iFp)
GO(gst_sdp_media_get_attribute, pFpu)
GO(gst_sdp_media_get_attribute_val, pFpp)
GO(gst_sdp_media_get_attribute_val_n, pFppu)
GO(gst_sdp_media_get_bandwidth, pFpu)
GO(gst_sdp_media_get_caps_from_media, pFpi)
GO(gst_sdp_media_get_connection, pFpu)
GO(gst_sdp_media_get_format, pFpu)
GO(gst_sdp_media_get_information, pFp)
GO(gst_sdp_media_get_key, pFp)
GO(gst_sdp_media_get_media, pFp)
GO(gst_sdp_media_get_num_ports, uFp)
GO(gst_sdp_media_get_port, uFp)
GO(gst_sdp_media_get_proto, pFp)
GO(gst_sdp_media_init, iFp)
GO(gst_sdp_media_insert_attribute, iFpip)
GO(gst_sdp_media_insert_bandwidth, iFpip)
GO(gst_sdp_media_insert_connection, iFpip)
GO(gst_sdp_media_insert_format, iFpip)
GO(gst_sdp_media_new, iFp)
GO(gst_sdp_media_parse_keymgmt, iFpp)
GO(gst_sdp_media_remove_attribute, iFpu)
GO(gst_sdp_media_remove_bandwidth, iFpu)
GO(gst_sdp_media_remove_connection, iFpu)
GO(gst_sdp_media_remove_format, iFpu)
GO(gst_sdp_media_replace_attribute, iFpup)
GO(gst_sdp_media_replace_bandwidth, iFpup)
GO(gst_sdp_media_replace_connection, iFpup)
GO(gst_sdp_media_replace_format, iFpup)
GO(gst_sdp_media_set_information, iFpp)
GO(gst_sdp_media_set_key, iFppp)
GO(gst_sdp_media_set_media, iFpp)
GO(gst_sdp_media_set_media_from_caps, iFpp)
GO(gst_sdp_media_set_port_info, iFpuu)
GO(gst_sdp_media_set_proto, iFpp)
GO(gst_sdp_media_uninit, iFp)
GO(gst_sdp_message_add_attribute, iFppp)
GO(gst_sdp_message_add_bandwidth, iFppu)
GO(gst_sdp_message_add_email, iFpp)
GO(gst_sdp_message_add_media, iFpp)
GO(gst_sdp_message_add_phone, iFpp)
GO(gst_sdp_message_add_time, iFpppp)
GO(gst_sdp_message_add_zone, iFppp)
GO(gst_sdp_message_as_text, pFp)
GO(gst_sdp_message_as_uri, pFpp)
GO(gst_sdp_message_attributes_len, uFp)
GO(gst_sdp_message_attributes_to_caps, iFpp)
GO(gst_sdp_message_bandwidths_len, uFp)
GO(gst_sdp_message_copy, iFpp)
GO(gst_sdp_message_dump, iFp)
GO(gst_sdp_message_emails_len, uFp)
GO(gst_sdp_message_free, iFp)
GO(gst_sdp_message_get_attribute, pFpu)
GO(gst_sdp_message_get_attribute_val, pFpp)
GO(gst_sdp_message_get_attribute_val_n, pFppu)
GO(gst_sdp_message_get_bandwidth, pFpu)
GO(gst_sdp_message_get_connection, pFp)
GO(gst_sdp_message_get_email, pFpu)
GO(gst_sdp_message_get_information, pFp)
GO(gst_sdp_message_get_key, pFp)
GO(gst_sdp_message_get_media, pFpu)
GO(gst_sdp_message_get_origin, pFp)
GO(gst_sdp_message_get_phone, pFpu)
GO(gst_sdp_message_get_session_name, pFp)
GO(gst_sdp_message_get_time, pFpu)
GO(gst_sdp_message_get_type, LFv)
GO(gst_sdp_message_get_uri, pFp)
GO(gst_sdp_message_get_version, pFp)
GO(gst_sdp_message_get_zone, pFpu)
GO(gst_sdp_message_init, iFp)
GO(gst_sdp_message_insert_attribute, iFpip)
GO(gst_sdp_message_insert_bandwidth, iFpip)
GO(gst_sdp_message_insert_email, iFpip)
GO(gst_sdp_message_insert_phone, iFpip)
GO(gst_sdp_message_insert_time, iFpip)
GO(gst_sdp_message_insert_zone, iFpip)
GO(gst_sdp_message_medias_len, uFp)
GO(gst_sdp_message_new, iFp)
GO(gst_sdp_message_new_from_text, iFpp)
GO(gst_sdp_message_parse_buffer, iFpup)
GO(gst_sdp_message_parse_keymgmt, iFpp)
GO(gst_sdp_message_parse_uri, iFpp)
GO(gst_sdp_message_phones_len, uFp)
GO(gst_sdp_message_remove_attribute, iFpu)
GO(gst_sdp_message_remove_bandwidth, iFpu)
GO(gst_sdp_message_remove_email, iFpu)
GO(gst_sdp_message_remove_phone, iFpu)
GO(gst_sdp_message_remove_time, iFpu)
GO(gst_sdp_message_remove_zone, iFpu)
GO(gst_sdp_message_replace_attribute, iFpup)
GO(gst_sdp_message_replace_bandwidth, iFpup)
GO(gst_sdp_message_replace_email, iFpup)
GO(gst_sdp_message_replace_phone, iFpup)
GO(gst_sdp_message_replace_time, iFpup)
GO(gst_sdp_message_replace_zone, iFpup)
GO(gst_sdp_message_set_connection, iFppppuu)
GO(gst_sdp_message_set_information, iFpp)
GO(gst_sdp_message_set_key, iFppp)
GO(gst_sdp_message_set_origin, iFppppppp)
GO(gst_sdp_message_set_session_name, iFpp)
GO(gst_sdp_message_set_uri, iFpp)
GO(gst_sdp_message_set_version, iFpp)
GO(gst_sdp_message_times_len, uFp)
GO(gst_sdp_message_uninit, iFp)
GO(gst_sdp_message_zones_len, uFp)
GO(gst_sdp_time_clear, iFp)
GO(gst_sdp_time_set, iFpppp)
GO(gst_sdp_zone_clear, iFp)
GO(gst_sdp_zone_set, iFppp)
