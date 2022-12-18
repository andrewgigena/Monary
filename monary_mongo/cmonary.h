

void monary_insert(mongoc_collection_t *collection, monary_column_data *coldata,
                   monary_column_data *id_data, mongoc_client_t *client,
                   mongoc_write_concern_t *write_concern, bson_error_t *err);
int monary_mask_failed_writes(bson_iter_t *errors, unsigned char *mask,
                              int offset);
void monary_bson_from_columns(monary_column_item *columns, int row,
                              int col_start, int col_end, bson_t *parent,
                              int name_offset, int depth);
void monary_make_bson_value_t(bson_value_t *val, monary_column_item *citem,
                              int idx);
void monary_destroy_write_concern(mongoc_write_concern_t *write_concern);
mongoc_write_concern_t *monary_create_write_concern(int write_concern_w,
                                                    int write_concern_wtimeout,
                                                    bool write_concern_journal,
                                                    bool write_concern_fsync,
                                                    char *write_concern_wtag);
void monary_close_query(monary_cursor *cursor);
int monary_load_query(monary_cursor *cursor, bson_error_t *err);
monary_cursor *monary_init_aggregate(mongoc_collection_t *collection,
                                     const uint8_t *pipeline,
                                     monary_column_data *coldata,
                                     bson_error_t *err);
monary_cursor *monary_init_query(mongoc_collection_t *collection,
                                 uint32_t offset, uint32_t limit,
                                 const uint8_t *query,
                                 monary_column_data *coldata, int select_fields,
                                 bson_error_t *err);
void monary_get_bson_fields_list(monary_column_data *coldata,
                                 bson_t *fields_bson);
int64_t monary_query_count(mongoc_collection_t *collection,
                           const uint8_t *query, bson_error_t *err);
int monary_bson_to_arrays(monary_column_data *coldata, unsigned int row,
                          const bson_t *bson_data);
int monary_load_item(const bson_iter_t *bsonit, monary_column_item *citem,
                     int offset);
int monary_load_length_value(const bson_iter_t *bsonit,
                             monary_column_item *citem, int idx);
int monary_load_size_value(const bson_iter_t *bsonit, monary_column_item *citem,
                           int idx);
int monary_load_type_value(const bson_iter_t *bsonit, monary_column_item *citem,
                           int idx);
int monary_load_document_value(const bson_iter_t *bsonit,
                               monary_column_item *citem, int idx);
int monary_load_binary_value(const bson_iter_t *bsonit,
                             monary_column_item *citem, int idx);
int monary_load_string_value(const bson_iter_t *bsonit,
                             monary_column_item *citem, int idx);
int monary_load_timestamp_value(const bson_iter_t *bsonit,
                                monary_column_item *citem, int idx);
MONARY_DEFINE_INT_LOADER(monary_load_int8_value, int8_t)
MONARY_DEFINE_INT_LOADER(
    monary_load_int16_value,
    int16_t) MONARY_DEFINE_INT_LOADER(monary_load_int32_value, int32_t)
    MONARY_DEFINE_INT_LOADER(
        monary_load_int64_value,
        int64_t) MONARY_DEFINE_INT_LOADER(monary_load_uint8_value, uint8_t)
        MONARY_DEFINE_INT_LOADER(monary_load_uint16_value, uint16_t)
            MONARY_DEFINE_INT_LOADER(monary_load_uint32_value, uint32_t)
                MONARY_DEFINE_INT_LOADER(
                    monary_load_uint64_value,
                    uint64_t) int monary_load_datetime_value(const bson_iter_t
                                                                 *bsonit,
                                                             monary_column_item
                                                                 *citem,
                                                             int idx);
int monary_load_bool_value(const bson_iter_t *bsonit, monary_column_item *citem,
                           int idx);
int monary_load_objectid_value(const bson_iter_t *bsonit,
                               monary_column_item *citem, int idx);
int monary_set_column_item(monary_column_data *coldata, unsigned int colnum,
                           const char *field, unsigned int type,
                           unsigned int type_arg, void *storage,
                           unsigned char *mask, bson_error_t *err);
int monary_free_column_data(monary_column_data *coldata);
monary_column_data *monary_alloc_column_data(unsigned int num_columns,
                                             unsigned int num_rows);
void monary_destroy_collection(mongoc_collection_t *collection);
mongoc_collection_t *monary_use_collection(mongoc_client_t *client,
                                           const char *db,
                                           const char *collection);
void monary_disconnect(mongoc_client_t *client);
mongoc_client_t *monary_connect(const char *uri, const char *pem_file,
                                const char *pem_pwd, const char *ca_file,
                                const char *ca_dir, const char *crl_file,
                                bool weak_cert_validation, bson_error_t *err);
void monary_cleanup(void);
void monary_init(void);
void monary_log_func(mongoc_log_level_t log_level, const char *log_domain,
                     const char *message, void *user_data);
void monary_error(bson_error_t *err, char *message);
void initlibcmonary(void);
