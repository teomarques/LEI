/////////////////////////////////////////////////////////////
//
// pgAdmin 4 - PostgreSQL Tools
//
// Copyright (C) 2013 - 2025, The pgAdmin Development Team
// This software is released under the PostgreSQL Licence
//
//////////////////////////////////////////////////////////////

define('pgadmin.user_management.current_user', [], function() {
    return {
        'id': 1,
        'email': 'teomarques@gmail.com',
        'is_admin': true,
        'name': 'teomarques',
        'allow_save_password': true,
        'allow_save_tunnel_password': false,
        'auth_sources': ['internal'],
        'current_auth_source': 'internal'
    }
});