/**
 * Tatoeba wiki  Wiki made with cppcmsskel
 * Copyright (C) 2012 Allan SIMON <allan.simon@supinfo.com> 
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @category Tatoeba wiki
 * @package  Models
 * @author   Allan SIMON <allan.simon@supinfo.com> 
 * @license  Affero General Public License
 * @link     https://github.com/sysko/tatowiki
 */

#ifndef TatoWiki_ARTICLES
#define TatoWiki_ARTICLES



#include "cppcms_skel/models/SqliteModel.h"

#include "results/Articles.h"
namespace models {


/**
 * @class Articles
 * 
 * @brief @TODO
 * @since 30 October 2012       
 *
 */
class Articles : public SqliteModel {
    public:
        /**
         * @brief Constructor
         * @since 30 October 2012
         */
        Articles();

        /**
         * @brief Retrieve an article using the couple (lang,slug)
         *        that we extract from the URL
         * 
         * @param lang ISO code of the language in which the article
         *             is written
         * @param slug Slug of the article (i.e URL version of the
         *             title)
         *
         * @return The article corresponding to the criteria
         *
         * @since 30 October 2012
         */
        results::Article get_from_lang_and_slug(
            const std::string &lang,
            const std::string &slug
        );
};

} // end namespace models 

#endif
