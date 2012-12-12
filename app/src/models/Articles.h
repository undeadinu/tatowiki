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


#include <cppcms_skel/models/SqliteModel.h>

#include "results/Articles.h"

#define ARTICLE_CREATION_ERROR -1
#define ARTICLE_DOESNT_EXIST_ERROR -2
#define ARTICLE_ALREADY_TRANSLATED_ERROR -3
#define ARTICLE_CREATE_TRANSLATION_ERROR -4
#define ARTICLE_ADD_TRANSLATION_LINK_ERROR -5

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


        /**
         * @brief Save a new version of an article
         * 
         * @param lang    ISO code of the language in which the article
         *                is written
         * @param slug    Slug of the article (i.e URL version of the
         *                title)
         * @param title   The title of the article
         * @param content The main content of the article
         *
         * @return bool If the article has been correctly edited
         *
         * @since 30 October 2012
         */

        bool edit_from_lang_and_slug(
            const std::string &lang,
            const std::string &slug,
            const std::string &title,
            const std::string &content
        );

        /**
         * @brief Save a new article
         * 
         * @param lang    ISO code of the language in which the article
         *                is written
         * @param slug    Slug of the article (i.e URL version of the
         *                title)
         * @param title   The title of the article
         * @param content The main content of the article
         *
         * @return Id of the article that has been created
         *         or a negative value in case of errors
         *
         * @since 4 November 2012
         */
        int create_from_lang_and_slug(
            const std::string &lang,
            const std::string &slug,
            const std::string &title,
            const std::string &content
        );

        /**
         * @brief Remove an article from the list of viewable article
         *        it is actually not deleted totally in order to be able
         *        to revert it in case of error/vandalism
         * 
         * @param lang    ISO code of the language in which the article
         *                is written
         * @param slug    Slug of the article (i.e URL version of the
         *                title)
         * 
         * @return bool True if the articles as been removed correctly
         *
         * @since 16 November 2012
         *
         */
        bool remove(
            const std::string &lang,
            const std::string &slug
        );

        /**
         * @brief Retrieve the complit list of Articles (only the "title" part)
         *
         * @return Articles List of articles
         *
         * @since 18 November 2012
         */
        results::Articles get_all();

        /**
         * @brief Translate an article in an other language 
         * 
         * @param lang    ISO code of the language in which the article
         *                is written
         * @param slug    Slug of the article (i.e URL version of the
         *                title)
         * @param title   The title of the article
         * @param content The main content of the article
         *
         * @return Id of the translation, or a negative number
         *         if something wrong happens
         *
         * @since 4 November 2012
         */
        int translate_from_lang_and_slug(
            const std::string &origLang,
            const std::string &origSlug,
            const std::string &lang,
            const std::string &slug,
            const std::string &title,
            const std::string &content
        );

        /**
         * @brief Retrieve the id of an article based on its
         *        Lang and URL name
         *
         * @param lang Lang in which the article is
         * @param slug URL name of the article
         *
         * @return Id of the article, or a negative number
         *         if the articles does not exists or other
         *         kind of problems happen
         *
         * @since 28 November 2012
         */
        int get_id_from_lang_and_slug(
            const std::string &lang,
            const std::string &slug
        );
        
        /**
         * @brief add a "translation" link between two articles
         *        Note: it does not any test beforehand, so
         *        be sure the two ids exists etc.
         * 
         * @param articleId
         * @param translationId
         */
        int add_translation_link(
            const int articleId,
            const int translationId
        );
        
        int is_translated_in(
            const int articleId,
            const std::string &lang
        );

    //end public 
};

} // end namespace models 

#endif
